#pragma once

#pragma once

#include <math.h>
#include "3D/mesh3D.hpp"

using namespace mesh3D;

class Sphere3D : public Mesh3D
{
public:
    Sphere3D(GLuint shaderID, int precision, float r = 1.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f)
        : Mesh3D(
            Sphere3D::vertices(precision, r, g, b, a),
            Sphere3D::indices(precision),
            shaderID
        ) {}

    std::vector<Vertex3D> vertices(int precision, float r, float g, float b, float a) {
        std::vector<Vertex3D> vertices;

        const float step = 1.0f / (float)precision;

        for (GLuint i = 0; i <= precision; ++i) {
            float theta = (float)i * step * M_PIf;
            for (GLuint j = 0; j < precision; ++j) {
                float phi = (float)j * step * 2.0f * M_PIf;
    
                float x = std::sin(theta) * std::sin(phi);
                float y = std::cos(theta);
                float z = std::sin(theta) * std::cos(phi);
    
                vertices.push_back(Vertex3D{ x, y, z, r, g, b, a });
            }
        }    
    
        return vertices;
    }

    std::vector<GLuint> indices(int precision) {
        std::vector<GLuint> indices;

        const float step = 1.0f / (float)precision;

        for (GLuint i = 0; i < precision; ++i) {
            for (GLuint j = 0; j < precision; ++j) {
                size_t _j = (j + 1) % precision;
    
                size_t idx0 = (i + 0) * precision +  j;
                size_t idx1 = (i + 1) * precision +  j;
                size_t idx2 = (i + 0) * precision + _j;
                size_t idx3 = (i + 1) * precision + _j;
    
                indices.push_back(idx0);
                indices.push_back(idx1);
                indices.push_back(idx2);
    
                indices.push_back(idx2);
                indices.push_back(idx1);
                indices.push_back(idx3);
            }
        }    

        return indices;
    }
};