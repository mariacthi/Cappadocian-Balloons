#version 330

layout(location = 0) in vec3 v_position;
layout(location = 1) in vec3 v_normal;
layout(location = 2) in vec2 v_texture_coord;
layout(location = 3) in vec3 v_color;

// Uniform properties
uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
uniform vec3 sphereCenter;
uniform int isSphere; 
uniform sampler2D heightmap;
uniform int isTerrain;
uniform float texelSize;
uniform float yOffset;
// Output
out vec2 texcoord;
out vec3 recalculatedNormal;
out vec3 world_position;
out vec3 world_normal;

void main()
{
	world_position = vec3(Model * vec4(v_position, 1.0));
    world_normal = normalize(mat3(Model) * v_normal);
    texcoord = v_texture_coord;

    vec3 localPosition = v_position;

   if (isTerrain == 1) {
        float h = texture(heightmap, v_texture_coord).r ;

        float h_right = texture(heightmap, v_texture_coord + vec2(texelSize, 0.0)).r ;
        float h_up = texture(heightmap, v_texture_coord + vec2(0.0, texelSize)).r;

        float deltaX = (h_right - h) * yOffset;
        float deltaZ = (h_up - h) * yOffset;

        vec3 TOS = (vec3(texelSize, deltaX, 0.0));
        vec3 BOS = (vec3(0.0, deltaZ, texelSize));

        vec3 normal = cross(BOS, TOS);
        recalculatedNormal = normalize((Model * vec4(normal, 0.0)).xyz);

        localPosition.y = h * yOffset;
    } else {
        recalculatedNormal = (Model * vec4(v_normal, 0.0)).xyz;
    }

    if (isSphere == 1) {
   
        localPosition -= sphereCenter;

        if (localPosition.y < 0.0) {
            float deformFactor = 1.0 + localPosition.y * 0.3; // Factor de deformare
            localPosition.x *= deformFactor;
            localPosition.z *= deformFactor;
        }

        localPosition += sphereCenter;
    }

    gl_Position = Projection * View * Model * vec4(localPosition, 1.0);
}
