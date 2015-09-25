#ifndef BASEOBJECT_H
#define	BASEOBJECT_H

#include <vector>
#include <fstream>

#include "ModelTransform.h"
#include "Mesh.h"
#include "Shader.h"
#include "Camera.h"
//#include <SFML/OpenGL.hpp>

class BaseObject
{
    public:
        virtual void draw(const Camera& camera) = 0;
        void setX(float val);
        void setY(float val);
        void setZ(float val);
        float getX();
        float getY();
        float getZ();
		// Model Transform
		ModelTransform* Transform();
	protected:
		Mesh m_mesh;
		Shader m_shader;
		ModelTransform m_transform;
		glm::vec3 m_color;
};

#endif /* BASEOBJECT_H */
