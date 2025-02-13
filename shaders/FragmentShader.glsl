#version 330

in vec2 texcoord;
in vec3 recalculatedNormal;
in vec3 world_position;
in vec3 world_normal;

// Uniforms
uniform sampler2D texture_1;
uniform sampler2D texture_2;
uniform float LOW_LIMIT;
uniform float HIGH_LIMIT;
uniform int isTerrain;
uniform int isBalloon;
uniform vec3 lightDir; 
uniform vec3 eye_position;
uniform int num_point_lights;
uniform vec3 light_position;
uniform vec3 light_color;
uniform float light_intensity;
struct PointLight {
    vec3 position;
    vec3 color;
    float intensity;
};

uniform PointLight point_lights[10];

uniform float material_kd;
uniform float material_ks;
uniform int material_shininess;

uniform vec3 lightDir2;     
uniform vec3 directionalColor;
uniform float directionalIntensity;

// Output
out vec4 out_color;

void main()
{
    vec3 normal = recalculatedNormal;
    vec3 ambient_light = vec3(0.25);

    vec3 L_directional = normalize(lightDir2);
    float diffuse_directional = max(dot(normal, L_directional), 0.0);
    vec3 diffuseColor = material_kd * directionalColor * diffuse_directional * directionalIntensity;

    vec3 final_light = ambient_light + diffuseColor;

    if (isTerrain == 1) {
        float height = texture(texture_1, texcoord).r;
        float normalizedHeight = clamp((height - LOW_LIMIT) / (HIGH_LIMIT - LOW_LIMIT), 0.0, 1.0);

        vec4 color1 = texture(texture_1, texcoord);
        vec4 color2 = texture(texture_2, texcoord);

        vec4 finalColor = mix(color1, color2, normalizedHeight);

        for (int i = 0; i < num_point_lights; ++i) {
            vec3 L = normalize(point_lights[i].position - world_position);
            float distance = length(point_lights[i].position - world_position);

            float radius = 5.0;
            if (distance < radius) {
                float attenuation = 1.0 - (distance / radius);

                float diffuse = material_kd * max(dot(L, normal), 0.0) * attenuation;
                vec3 V = normalize(eye_position - world_position);
                vec3 H = normalize(L + V);
                float specular = material_ks * pow(max(dot(H, normal), 0.0), material_shininess) * attenuation;

                final_light += (point_lights[i].color * point_lights[i].intensity) * (diffuse + specular);
            }
        }

        out_color = vec4(final_light, 1.0) * finalColor;
    } else if (isBalloon == 1) {
        vec3 L = normalize(light_position - world_position);
        vec3 V = normalize(eye_position - world_position);
        vec3 H = normalize(L + V);

        float diffuse_light = material_kd * max(dot(L, world_normal), 0.0);
        float specular_light = 0.0;

        if (diffuse_light > 0.0) {
            specular_light = material_ks * pow(max(dot(H, world_normal), 0.0), material_shininess);
        }

        vec3 final_light = light_color * light_intensity * (ambient_light + diffuse_light + specular_light);

        out_color = vec4(final_light, 1.0) * texture2D(texture_1, texcoord);
    } else {
        out_color = texture(texture_1, texcoord);
    }
}
