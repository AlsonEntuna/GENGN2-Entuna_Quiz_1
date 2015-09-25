#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
//added start
#include <GL/glew.h>
//added end
#include <vector>
#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex{
    public:
        Vertex(const glm::vec3 posVal){
            pos = posVal;
        }
    //private:
        glm::vec3 pos;
};

class Mesh{

public:    
    Mesh(Vertex* vertices,unsigned int numVertices);
    Mesh();
    void init(Vertex* vertices,unsigned int numVertices);
    ~Mesh();
    void draw();
private:
    //static const unsigned int NUM_BUFFERS = 4;
    enum{POSITION_VB,NUM_BUFFERS};

    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffers[NUM_BUFFERS];
    unsigned int n_drawCount;
};

#endif
