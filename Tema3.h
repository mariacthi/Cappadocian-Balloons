#pragma once

#include <string>
#include <unordered_map>

#include "components/simple_scene.h"
#include "components/transform.h"
#include "create.h"
#include "lab_camera.h"


namespace m1
{
    class Tema3 : public gfxc::SimpleScene
    {
    public:
        Tema3();
        ~Tema3();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, Texture2D* texture1 = NULL, Texture2D* texture2 = NULL, Texture2D* texture3 = NULL);
        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;
       
        void GenerateRandomBalloonPositions();
        void GenerateRandomLights();

        glm::mat4 projectionMatrix;
        std::unordered_map<std::string, Texture2D*> mapTextures;
        std::unordered_map<std::string, Mesh*> balloonMeshes;
        implemented::Camera3 *camera;
        int isSphere = 0;
        std::vector<glm::vec3> balloonPositions, lightPositions, lightColors;
        std::vector<float> lightIntensities;
        std::vector<std::string> balloonTextures;
        glm::vec3 centerSphere;
        float time = 0.0f;
        glm::vec3 forward = glm::vec3(0, 0, -1);
        glm::vec3 up = glm::vec3(0, 1, 0);
        glm::vec3 right = glm::cross(forward, up);
        int isTerrain = 0;
        unsigned int materialShininess = 30;
        float materialKd = 0.6;
        float materialKs = 0.6;
		int isBalloon = 0;
    };
}   // namespace m1
