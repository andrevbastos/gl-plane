#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "ifcg.hpp"
#include "plane.hpp"
#include "3D/camera3D.hpp"

unsigned int width = 800;
unsigned int height = 600;

int main()
{
    IFCG::init();
    IFCG::createWindow(width, height);

    Shader shader3D = IFCG::getDefaultShader3D();

    Camera3D camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

    Plane teste(shader3D.id);

    while (!IFCG::shouldClose())
    {
        IFCG::processInput();
        IFCG::clearBuffer(1.0f, 1.0f, 1.0f, 1.0f);

        shader3D.activate();
        
        camera.inputs(IFCG::window);
        camera.update(90.0f, 0.1f, 100.0f, shader3D.id);
        
        teste.inputs(IFCG::window);
        teste.draw();

        IFCG::swapBuffer();
        IFCG::readInputs();
    }

    IFCG::terminate();
    return 0;
}