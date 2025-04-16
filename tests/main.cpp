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

    Plane teste(shader3D.id, width, height);

    while (!IFCG::shouldClose())
    {
        IFCG::readInputs();
        IFCG::processInput();
        IFCG::clearBuffer(0.5f, 0.5f, 0.7f, 1.0f);

        shader3D.activate();
        
        teste.inputs(IFCG::window);
        teste.update();
        teste.draw();

        IFCG::swapBuffer();
    }

    IFCG::terminate();
    return 0;
}