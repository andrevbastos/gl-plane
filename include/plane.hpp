#pragma once

#include <GLFW/glfw3.h>

#include "3D/mesh3D.hpp"
#include "3D/cube_mesh3D.hpp"

namespace plane
{
    class Plane
    {
    public:
        Plane(GLuint shaderID);
        void draw();
        void inputs(GLFWwindow* window);
    private:
        float speed = 0.1f;

        Mesh3D mesh = Mesh3D({}, {}, 0);
    };

    Plane::Plane(GLuint shaderID)
    {
        Cube3D main(shaderID, 0.3f, 0.3f, 0.3f, 1.0f);
        main.scale(0.2f, 0.2f, 0.8f);

        Cube3D wings(shaderID, 0.35f, 0.35f, 0.35f, 1.0f);
        wings.translate(0.0f, 0.09f, 0.2f);
        wings.scale(0.8f, 0.1f, 0.2f);
    
        this->mesh = Mesh3D({main, wings}, shaderID);
    };  
     
    void Plane::draw()
    {
        this->mesh.draw();
    };

    void Plane::inputs(GLFWwindow* window)
	{
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		{
			mesh.translate(0.0f, 0.0f, speed);
		}
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		{
			mesh.translate(speed, 0.0f, 0.0f);
		}
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		{
			mesh.translate(0.0f, 0.0f, -speed);
		}
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		{
			mesh.translate(-speed, 0.0f, 0.0f);
		}
		if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		{
			mesh.translate(0.0f, speed, 0.0f);
		}
		if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
		{
			mesh.translate(0.0f, -speed, 0.0f);
		}
		if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
		{
			speed = 0.4f;
		}
		else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
		{
			speed = 0.1f;
		}
	}
    
}

using namespace plane;