#pragma once

#include <cmath>
#include <stdexcept>
#include "2D/mesh2D.hpp"

class Circle2D : public Mesh2D
{
public:
    Circle2D(GLuint shaderID, int precision, float r = 1.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f)
        : Mesh2D(
            Circle2D::vertices(precision, r, g, b, a),
            Circle2D::indices(precision),
            shaderID
        ) {}

    std::vector<Vertex2D> vertices(int precision, float r, float g, float b, float a) {
        if (precision < 3) {
            throw std::invalid_argument("Precision must be at least 3 to form a valid circle.");
        }

        std::vector<Vertex2D> vertices;
        vertices.reserve(precision + 1);
        
        vertices.push_back(Vertex2D{0.0f, 0.0f, r, g, b, a});
    
        float angleStep = 2.0f * M_PI / precision;
        for (int i = 0; i < precision; i++) {
            float currentAngle = i * angleStep;
            float x = cos(currentAngle);
            float y = sin(currentAngle);
            
            vertices.push_back(Vertex2D{x, y, r, g, b, a});
        }
    
        return vertices;
    }

    std::vector<GLuint> indices(int precision) {
        if (precision < 3) {
            throw std::invalid_argument("Precision must be at least 3 to form a valid circle.");
        }

        std::vector<GLuint> indices;
        indices.reserve(precision * 3);
        
        for (int i = 1; i <= precision; i++) {
            indices.push_back(0);
            indices.push_back(i);
            
            if (i < precision) {
                indices.push_back(i + 1);
            } else {
                indices.push_back(1);
            }
        }

        return indices;
    }
};