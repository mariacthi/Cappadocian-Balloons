#include "lab_m1/Tema3/Tema3.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema3::Tema3()
{
}


Tema3::~Tema3()
{
}


void Tema3::Init()
{
    const string sourceTextureDir = PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema3", "textures");
    camera = new implemented::Camera3();
    // Load textures
    

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "ground.jpg").c_str(), GL_REPEAT);
        mapTextures["ground"] = texture;
    }

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "crate.jpg").c_str(), GL_REPEAT);
        mapTextures["crate"] = texture;
    }

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "earth.png").c_str(), GL_REPEAT);
        mapTextures["earth"] = texture;
    }

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "vegetation", "bamboo", "bamboo.png").c_str(), GL_REPEAT);
        mapTextures["bamboo"] = texture;
    }
       
    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "fire.png").c_str(), GL_REPEAT);
        mapTextures["fire"] = texture;
    }

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "rain.png").c_str(), GL_REPEAT);
        mapTextures["rain"] = texture;
    }
    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "random.png").c_str(), GL_REPEAT);
        mapTextures["random"] = texture;
    }
    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "snowflake.png").c_str(), GL_REPEAT);
        mapTextures["snowflake"] = texture;
    }
    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "particle2.png").c_str(), GL_REPEAT);
        mapTextures["particle2"] = texture;
    }
    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "steag.jpg").c_str(), GL_REPEAT);
        mapTextures["steag"] = texture;
    }
    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "apa.jpg").c_str(), GL_REPEAT);
        mapTextures["apa"] = texture;
    }
    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "moon.jpg").c_str(), GL_REPEAT);
        mapTextures["moon"] = texture;
    }
    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "wood.jpg").c_str(), GL_REPEAT);
        mapTextures["wood"] = texture;
    }
    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "random1.jpg").c_str(), GL_REPEAT);
        mapTextures["random1"] = texture;
    }

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "checkered.jpeg").c_str(), GL_REPEAT);
        mapTextures["checkered"] = texture;
    }

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "random2.jpg").c_str(), GL_REPEAT);
        mapTextures["random2"] = texture;
    }

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "heightmap256.png").c_str(), GL_REPEAT);
        mapTextures["heightmap"] = texture;
    }

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "ground.jpg").c_str(), GL_REPEAT);
        mapTextures["ground1"] = texture;
    }

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "ground2.jpg").c_str(), GL_REPEAT);
        mapTextures["ground2"] = texture;
    }

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D(PATH_JOIN(sourceTextureDir, "sun2.jpg").c_str(), GL_REPEAT);
		mapTextures["sun"] = texture;
	}
	

   
    // Load meshes
    {
        Mesh* mesh = new Mesh("box");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "box.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("sphere");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "sphere.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("bamboo");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "vegetation", "bamboo"), "bamboo.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("terrain");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "plane256.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }


    // Create a simple quad
    {
        vector<glm::vec3> vertices
        {
            glm::vec3(0.5f,   0.5f, 0.0f),    // top right
            glm::vec3(0.5f,  -0.5f, 0.0f),    // bottom right
            glm::vec3(-0.5f, -0.5f, 0.0f),    // bottom left
            glm::vec3(-0.5f,  0.5f, 0.0f),    // top left
        };

        vector<glm::vec3> normals
        {
            glm::vec3(0, 1, 1),
            glm::vec3(1, 0, 1),
            glm::vec3(1, 0, 0),
            glm::vec3(0, 1, 0)
        };

        vector<glm::vec2> textureCoords
        {
            // TODO(student): Complete texture coordinates for the square
            glm::vec2(0.0f, 0.0f),
            glm::vec2(0.0f, 1.0f),
            glm::vec2(1.0f, 1.0f),
            glm::vec2(1.0f, 0.0f)

        };

        vector<unsigned int> indices =
        {
            0, 1, 3,
            1, 2, 3
        };

        Mesh* mesh = new Mesh("square");
        mesh->InitFromData(vertices, normals, textureCoords, indices);
        meshes[mesh->GetMeshID()] = mesh;
    }

    GenerateRandomBalloonPositions();
        
    glm::vec3 terrainStartPosition = glm::vec3(-20.0f, 1.0f, -20.0f); 
    glm::vec3 cameraPosition = terrainStartPosition + glm::vec3(0.0f, 3.0f, 20.0f);
    glm::vec3 cameraTarget = terrainStartPosition;
    glm::vec3 upVector = glm::vec3(0.0f, 1.0f, 0.0f);

    camera->Set(cameraPosition, cameraTarget, upVector);
    camera->RotateFirstPerson_OY(RADIANS(-90));
    {
        Shader* shader = new Shader("LabShader");
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema3", "shaders", "VertexShader.glsl"), GL_VERTEX_SHADER);
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema3", "shaders", "FragmentShader.glsl"), GL_FRAGMENT_SHADER);
        shader->CreateAndLink();
        shaders[shader->GetName()] = shader;

    }

    GenerateRandomLights();

    glUniform1f(glGetUniformLocation(shaders["LabShader"]->GetProgramID(), "directionalIntensity"), 1.5f);
}

void Tema3::GenerateRandomBalloonPositions() {
    std::vector<std::string> availableTextures = { "fire", "snowflake", "steag", "apa", "moon", "checkered", "random1", "random2" };

    for (int i = 0; i < availableTextures.size(); i++) {
        glm::vec3 position;
        bool isUnique;

        do {
            isUnique = true;

            float y = (rand() % 10)  / 3.0f;
            if (y < 1) {
                y = -y + 1;
            }
             
            float x = (rand() % 13);
            
			float z = (rand() % 13);
            
            position = glm::vec3(x, y, z);

            for (const auto& existingPosition : balloonPositions) {
                if (glm::distance(position, existingPosition) < 1.0f) {
                    isUnique = false;
                    break;
                }
            }

        } while (!isUnique);

        std::cout << "Balloon " << i << " at position " << position.x << " " << position.y << " " << position.z << std::endl;
        balloonPositions.push_back(position);
        balloonTextures.push_back(availableTextures[i]);
    }
}

void Tema3::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0.4, 0.6, 0.8, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}

void Tema3::Update(float deltaTimeSeconds)
{
    glm::mat4 sunModelMatrix = glm::mat4(1);
    sunModelMatrix = glm::translate(sunModelMatrix, glm::vec3(25, 10, 25));
    sunModelMatrix = glm::scale(sunModelMatrix, glm::vec3(7, 7, 7));
    RenderSimpleMesh(meshes["sphere"], shaders["LabShader"], sunModelMatrix, mapTextures["sun"]);

    time += deltaTimeSeconds;
    float speed = 0.05f;
    float amplitude = 0.6f;
    float frequency = 0.5f;
    float hillsHeight = 2.0f;
    
    glm::vec3 boxSize = glm::vec3(0.5, 0.15, 0.3);
    glm::vec3 connectorSize = glm::vec3(0.025, 0.45, 0.025);
    glm::vec3 balloonScale = glm::vec3(1.25);
    centerSphere = glm::vec3(0, boxSize.y / 2 + connectorSize.y + 0.4, 0);
    
    isBalloon = 1;
    for (size_t i = 0; i < balloonPositions.size(); i++) {
        glm::vec3 initialPosition = balloonPositions[i];

        speed += 0.01 * i;
        
        float radius = sqrt(initialPosition.x * initialPosition.x + initialPosition.z + initialPosition.z);
        float angle = speed * time + i * glm::radians(45.0f);

        float x = radius * cos(angle);
        float z = radius * sin(angle);
        float y = initialPosition.y + amplitude * sin(frequency * time + i * 0.1) + hillsHeight;


        glm::vec3 currentPosition = glm::vec3(x, y, z);

        lightPositions[i] = currentPosition;
        glUniform3fv(glGetUniformLocation(shaders["LabShader"]->GetProgramID(), "light_position"), 1, glm::value_ptr(currentPosition));
        glUniform3fv(glGetUniformLocation(shaders["LabShader"]->GetProgramID(), "light_color"), 1, glm::value_ptr(lightColors[i]));
        glUniform1f(glGetUniformLocation(shaders["LabShader"]->GetProgramID(), "light_intensity"), lightIntensities[i]);
   
        glm::mat4 boxModelMatrix = glm::mat4(1);
        boxModelMatrix = glm::translate(boxModelMatrix, currentPosition);
        boxModelMatrix = glm::scale(boxModelMatrix, boxSize);
        RenderSimpleMesh(meshes["box"], shaders["LabShader"], boxModelMatrix, mapTextures["crate"]);

        for (int j = 0; j < 4; ++j) {
            float xOffset = (j % 2 == 0 ? 1 : -1) * (boxSize.x / 2 - 0.02f);
            float zOffset = (j / 2 == 0 ? 1 : -1) * boxSize.z / 2;
            glm::vec3 connectorPos = currentPosition + glm::vec3(xOffset, boxSize.y / 2 + connectorSize.y / 2, zOffset);

            glm::mat4 connectorModelMatrix = glm::mat4(1);
            connectorModelMatrix = glm::translate(connectorModelMatrix, connectorPos);
            connectorModelMatrix = glm::scale(connectorModelMatrix, connectorSize);
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], connectorModelMatrix, mapTextures["crate"]);
        }

        glm::mat4 balloonModelMatrix = glm::mat4(1);
        balloonModelMatrix = glm::translate(balloonModelMatrix, currentPosition + centerSphere);
        balloonModelMatrix = glm::scale(balloonModelMatrix, balloonScale);
        isSphere = 1;
        RenderSimpleMesh(meshes["sphere"], shaders["LabShader"], balloonModelMatrix, mapTextures[balloonTextures[i]]);
        isSphere = 0;
    }
    isBalloon = 0;

    glm::mat4 terrainModelMatrix = glm::mat4(1);
    terrainModelMatrix = glm::scale(terrainModelMatrix, glm::vec3(35, 10, 35));
    isTerrain = 1;
    RenderSimpleMesh(meshes["terrain"], shaders["LabShader"], terrainModelMatrix, mapTextures["ground1"], mapTextures["ground2"], mapTextures["heightmap"]);
    isTerrain = 0;
}


void Tema3::GenerateRandomLights() {
    int numPointLights = balloonPositions.size();

    for (int i = 0; i < numPointLights; i++) {
        glm::vec3 lightPosition = balloonPositions[i] - glm::vec3(3.0, 3.0, 3.0);

        glm::vec3 lightColor = glm::vec3(
            static_cast<float>(rand()) / RAND_MAX, // R
            static_cast<float>(rand()) / RAND_MAX, // G
            static_cast<float>(rand()) / RAND_MAX  // B
        );

        float lightIntensity = 5.0f + static_cast<float>(rand()) / (RAND_MAX / 8.0f);

        lightPositions.push_back(lightPosition);
        lightColors.push_back(lightColor);
        lightIntensities.push_back(lightIntensity);

        std::cout << "Light " << i << " at position " << lightPosition.x << " " << lightPosition.y << " " << lightPosition.z
            << " with color (" << lightColor.r << ", " << lightColor.g << ", " << lightColor.b << ")"
            << " and intensity " << lightIntensity << std::endl;
    }
}


void Tema3::FrameEnd()
{
    //DrawCoordinateSystem();
}


void Tema3::RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, Texture2D* texture1, Texture2D* texture2, Texture2D* texture3)
{
    if (!mesh || !shader || !shader->GetProgramID())
        return;

    // Render an object using the specified shader and the specified position
    glUseProgram(shader->program);
  
    // Bind model matrix
    GLint loc_model_matrix = glGetUniformLocation(shader->program, "Model");
    glUniformMatrix4fv(loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));
   
    // Bind view matrix
    glm::mat4 viewMatrix = camera->GetViewMatrix();
    int loc_view_matrix = glGetUniformLocation(shader->program, "View");
    glUniformMatrix4fv(loc_view_matrix, 1, GL_FALSE, glm::value_ptr(viewMatrix));

    // Bind projection matrix
    glm::mat4 projectionMatrix = glm::perspective(RADIANS(70), window->props.aspectRatio, 0.01f, 200.0f);
    int loc_projection_matrix = glGetUniformLocation(shader->program, "Projection");
    glUniformMatrix4fv(loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

    // Set eye position (camera position) uniform
    glm::vec3 eyePosition = GetSceneCamera()->m_transform->GetWorldPosition();
    int eye_position = glGetUniformLocation(shader->program, "eye_position");
    glUniform3f(eye_position, eyePosition.x, eyePosition.y, eyePosition.z);

    int material_shininess = glGetUniformLocation(shader->program, "material_shininess");
    glUniform1i(material_shininess, materialShininess);

    int material_kd = glGetUniformLocation(shader->program, "material_kd");
    glUniform1f(material_kd, materialKd);

    int material_ks = glGetUniformLocation(shader->program, "material_ks");
    glUniform1f(material_ks, materialKs);

    int sphereCenterLocation = glGetUniformLocation(shader->program, "sphereCenter");
    glUniform3fv(sphereCenterLocation, 1, glm::value_ptr(centerSphere));
   
    int isSpherelocation = glGetUniformLocation(shader->program, "isSphere");
    glUniform1i(isSpherelocation, isSphere);
    
    int isTerrainlocation = glGetUniformLocation(shader->program, "isTerrain");
    glUniform1i(isTerrainlocation, isTerrain);

	int isBalloonlocation = glGetUniformLocation(shader->program, "isBalloon");
	glUniform1i(isBalloonlocation, isBalloon);

    glUniform3fv(glGetUniformLocation(shaders["LabShader"]->GetProgramID(), "lightDir2"), 1, glm::value_ptr(glm::vec3(1.0f, 3.0f, 1.0f)));
    glUniform3fv(glGetUniformLocation(shaders["LabShader"]->GetProgramID(), "directionalColor"), 1, glm::value_ptr(glm::vec3(1.0f, 0.7f, 0.7f))); // Culoarea galbenă a soarelui
  //  glUniform1f(glGetUniformLocation(shaders["LabShader"]->GetProgramID(), "directionalIntensity"), 0.7f); // Intensitatea luminii direcționale

    glUniform1f(glGetUniformLocation(shader->program, "texelSize"), 1.0f / 256.0f);
    glUniform1f(glGetUniformLocation(shader->program, "yOffset"), 0.5f);
    glUniform3fv(glGetUniformLocation(shader->program, "lightDir"), 1, glm::value_ptr(glm::vec3(0.0f, -1.0f, -1.0f)));

	int numPointLights = balloonPositions.size();
    for (int i = 0; i < numPointLights; i++) {
        string uniformName = "point_lights[" + to_string(i) + "]";
        glUniform3fv(glGetUniformLocation(shader->program, (uniformName + ".position").c_str()), 1, glm::value_ptr(lightPositions[i]));
        glUniform3fv(glGetUniformLocation(shader->program, (uniformName + ".color").c_str()), 1, glm::value_ptr(lightColors[i]));
        glUniform1f(glGetUniformLocation(shader->program, (uniformName + ".intensity").c_str()), lightIntensities[i]);
    }
    glUniform1i(glGetUniformLocation(shader->program, "num_point_lights"), numPointLights);

    if (texture1) {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1->GetTextureID());
        glUniform1i(glGetUniformLocation(shader->program, "texture_1"), 0);
    }

    if (texture2) {
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2->GetTextureID());
        glUniform1i(glGetUniformLocation(shader->program, "texture_2"), 1);
    }

    if (texture3) {
        glActiveTexture(GL_TEXTURE2);
        glBindTexture(GL_TEXTURE_2D, texture3->GetTextureID());
        glUniform1i(glGetUniformLocation(shader->program, "heightmap"), 2);
    }

    if (isTerrain) {
        glUniform1f(glGetUniformLocation(shader->program, "LOW_LIMIT"), 0.005f);
        glUniform1f(glGetUniformLocation(shader->program, "HIGH_LIMIT"), 0.1f);
    }

    glBindVertexArray(mesh->GetBuffers()->m_VAO);
    glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_INT, 0);
}



/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema3::OnInputUpdate(float deltaTime, int mods)
{
    float speed = 2.0f;
    if (window->KeyHold(GLFW_KEY_W)) {
		camera->TranslateForward(speed * deltaTime);
    }
    if (window->KeyHold(GLFW_KEY_S)) {
		camera->TranslateForward(-speed * deltaTime);
    }
    if (window->KeyHold(GLFW_KEY_A)) {
		camera->TranslateRight(-speed * deltaTime);
    }
    if (window->KeyHold(GLFW_KEY_D)) {
		camera->TranslateRight(speed * deltaTime);
    }
    if (window->KeyHold(GLFW_KEY_Q)) {
		camera->TranslateUpward(speed * deltaTime);
    }
    if (window->KeyHold(GLFW_KEY_E)) {
		camera->TranslateUpward(-speed * deltaTime);
    }
    if (window->KeyHold(GLFW_KEY_F)) {
        camera->RotateFirstPerson_OY(-speed * deltaTime);
    }
	if (window->KeyHold(GLFW_KEY_G)) {
		camera->RotateFirstPerson_OY(speed * deltaTime);
	}
	if (window->KeyHold(GLFW_KEY_R)) {
        glUniform1f(glGetUniformLocation(shaders["LabShader"]->GetProgramID(), "directionalIntensity"), 1.5f);
	} 
	if (window->KeyHold(GLFW_KEY_T)) {
		glUniform1f(glGetUniformLocation(shaders["LabShader"]->GetProgramID(), "directionalIntensity"), 0.0f);
	}
   

}


void Tema3::OnKeyPress(int key, int mods)
{
    // Add key press event
}


void Tema3::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema3::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
}


void Tema3::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
}


void Tema3::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Tema3::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema3::OnWindowResize(int width, int height)
{
}
