#include "Cube.h"

Cube::Cube(){}

Cube::Cube(float r, float g, float b, float size)
{
	// Set sizes to the tiles and cube
	tileSize = size;
	init(r, g, b, cubeSize);
}

// USE: To Create 3D Cube
void Cube::init(float r, float g, float b, float size)
{
	cubeSize = (size - 0.1f) / 2;
	m_color.x = r;
	m_color.y = g;
	m_color.z = b;
	// Vertex Buffer
	Vertex vertices[] = 
	{
		// Triangle 1
		Vertex(glm::vec3( cubeSize,  cubeSize, cubeSize)),
		Vertex(glm::vec3(-cubeSize,  cubeSize, cubeSize)),
		Vertex(glm::vec3(-cubeSize, -cubeSize, cubeSize)),

		// Triangle 2
		Vertex(glm::vec3(-cubeSize, -cubeSize, cubeSize)), 
		Vertex(glm::vec3( cubeSize, -cubeSize, cubeSize)),
		Vertex(glm::vec3( cubeSize,  cubeSize, cubeSize)), 

		// Trinagle 3
		Vertex(glm::vec3(cubeSize,  cubeSize,  cubeSize)), 
		Vertex(glm::vec3(cubeSize, -cubeSize,  cubeSize)),
		Vertex(glm::vec3(cubeSize, -cubeSize, -cubeSize)),

		// Triangle 4
		Vertex(glm::vec3(cubeSize, -cubeSize, -cubeSize)),
		Vertex(glm::vec3(cubeSize,  cubeSize, -cubeSize)),
		Vertex(glm::vec3(cubeSize,  cubeSize,  cubeSize)),

		// Triangle 5
		Vertex(glm::vec3( cubeSize, cubeSize,  cubeSize)),
		Vertex(glm::vec3( cubeSize, cubeSize, -cubeSize)),
		Vertex(glm::vec3(-cubeSize, cubeSize, -cubeSize)),

		// Triangle 6
		Vertex(glm::vec3(-cubeSize, cubeSize, -cubeSize)), 
		Vertex(glm::vec3(-cubeSize, cubeSize,  cubeSize)),
		Vertex(glm::vec3( cubeSize, cubeSize,  cubeSize)),

		// Trinagle 7
		Vertex(glm::vec3(-cubeSize,  cubeSize,  cubeSize)), 
		Vertex(glm::vec3(-cubeSize, -cubeSize,  cubeSize)),
		Vertex(glm::vec3(-cubeSize, -cubeSize, -cubeSize)),

		// Triangle 8
		Vertex(glm::vec3(-cubeSize, -cubeSize, -cubeSize)), 
		Vertex(glm::vec3(-cubeSize,  cubeSize, -cubeSize)),
		Vertex(glm::vec3(-cubeSize,  cubeSize,  cubeSize)),

		// Triangle 9
		Vertex(glm::vec3( cubeSize,  cubeSize, -cubeSize)),
		Vertex(glm::vec3(-cubeSize,  cubeSize, -cubeSize)),
		Vertex(glm::vec3(-cubeSize, -cubeSize, -cubeSize)),

		// Triangle 10
		Vertex(glm::vec3(-cubeSize, -cubeSize, -cubeSize)), 
		Vertex(glm::vec3( cubeSize, -cubeSize, -cubeSize)),
		Vertex(glm::vec3( cubeSize,  cubeSize, -cubeSize)),

		// Triangle 11
		Vertex(glm::vec3( cubeSize, -cubeSize,  cubeSize)), 
		Vertex(glm::vec3( cubeSize, -cubeSize, -cubeSize)),
		Vertex(glm::vec3(-cubeSize, -cubeSize, -cubeSize)),

		// Triangle 12
		Vertex(glm::vec3(-cubeSize, -cubeSize, -cubeSize)),
		Vertex(glm::vec3(-cubeSize, -cubeSize,  cubeSize)),
		Vertex(glm::vec3( cubeSize, -cubeSize,  cubeSize)),
	};

	// Initialize
	m_mesh.init(vertices, sizeof(vertices)/sizeof(vertices[0]));
	m_shader.init((char*)"res/basicShader");
}

void Cube::draw(const Camera& camera)
{
	m_shader.bind(); // binds the shader to the mesh
	m_shader.update(m_transform, camera, m_color); // updates the shader 
	m_mesh.draw(); // draws the mesh
}

void Cube::moveUP()
{
	m_transform.GetPos()->y += tileSize;
	//y+=tileSize;
}
void Cube::moveDOWN()
{
	m_transform.GetPos()->y -= tileSize;
	//y-=tileSize;
}
void Cube::moveLEFT()
{
	m_transform.GetPos()->x -= tileSize;
	//x-=tileSize;
}
void Cube::moveRIGHT()
{
	m_transform.GetPos()->x += tileSize;
	//x+=tileSize;
}
