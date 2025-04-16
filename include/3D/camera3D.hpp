#pragma once 

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

#include "shader/shader.hpp"

namespace camera
{
	class Camera3D {
		public:
			Camera3D(int width, int height, glm::vec3 position);
			void update(float FOVdeg, float nearPlane, float farPlane, GLuint shaderID);
			void followTarget(const glm::vec3& targetPos, const glm::vec3& targetForward, const glm::vec3& planeUp);
		private:
			glm::vec3 position;
			glm::vec3 orientation = glm::vec3(0.0f, 0.0f, -1.0f);
			glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
			glm::vec3 targetPosition;
			glm::vec3 offset = glm::vec3(0.0f, 2.0f, -3.0f); 

			bool firstClick = true;
			int width;
			int height;
		};

	Camera3D::Camera3D(int width, int height, glm::vec3 position)
		: width(width), height(height), position(position) {}

	void Camera3D::update(float FOVdeg, float nearPlane, float farPlane, GLuint shaderID)
	{
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);

		view = glm::lookAt(position, position + orientation, up);
		projection = glm::perspective(glm::radians(FOVdeg), (float)width / height, nearPlane, farPlane);

		glUniformMatrix4fv(
			glGetUniformLocation(shaderID, "cam"),
			1,
			GL_FALSE,
			glm::value_ptr(projection * view)
		);
	}

	void Camera3D::followTarget(const glm::vec3& targetPos, const glm::vec3& targetForward, const glm::vec3& planeUp) {
		glm::vec3 desiredPosition = targetPos - (targetForward * offset.z) + (planeUp * offset.y);
	
		position = glm::mix(position, desiredPosition, 0.1f);
	
		glm::vec3 lookAtPoint = targetPos + (targetForward / 4.0f);
		orientation = glm::normalize(lookAtPoint - position);
	
		up = glm::normalize(planeUp);
	}

}

using namespace camera;