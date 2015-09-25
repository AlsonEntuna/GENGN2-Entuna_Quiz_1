#include "Cube.h"

Cube::Cube(){}

Cube::Cube(float r, float g, float b, float size)
{
	init(r, g, b, size);
	// Set sizes to the tiles and cube
	tileSize = size;
	cubeSize = (size - 0.1f) / 2;
}

// USE: To Create 3D Cube
void Cube::init(float r, float g, float b, float size)
{
	m_color.x = r;
	m_color.y = g;
	m_color.z = b;
	// Vertex Buffer
	Vertex vertices[] = 
	{
		Vertex(glm::vec3(size, size, size)), // Triangle 1
		Vertex(glm::vec3(-size, size, size)),
		Vertex(glm::vec3(-size, -size, size)),

		Vertex(glm::vec3(-size, -size, size)), // Triangle 2
		Vertex(glm::vec3(size, -size, size)),
		Vertex(glm::vec3(size, size, size)), 

		Vertex(glm::vec3(size, size, size)), // Trinagle 3
		Vertex(glm::vec3(size, -size, size)),
		Vertex(glm::vec3(size, -size, -size)),

		Vertex(glm::vec3(size, -size, -size)), // Triangle 4
		Vertex(glm::vec3(size, size, -size)),
		Vertex(glm::vec3(size, size, size)),

		Vertex(glm::vec3(size, size, size)), // Triangle 5
		Vertex(glm::vec3(size, size, -size)),
		Vertex(glm::vec3(-size, size, -size)),

		Vertex(glm::vec3(-size, size, -size)), // Triangle 6
		Vertex(glm::vec3(-size, size, size)),
		Vertex(glm::vec3(size, size, size)),

		Vertex(glm::vec3(-size, size, size)), // Trinagle 7
		Vertex(glm::vec3(-size, -size, size)),
		Vertex(glm::vec3(-size, -size, -size)),

		Vertex(glm::vec3(-size, -size, -size)), // Triangle 8
		Vertex(glm::vec3(-size, size, -size)),
		Vertex(glm::vec3(-size, size, size)),

		Vertex(glm::vec3(size, size, -size)), // Triangle 9
		Vertex(glm::vec3(-size, size, -size)),
		Vertex(glm::vec3(-size, -size, -size)),

		Vertex(glm::vec3(-size, -size, -size)),  // Triangle 10
		Vertex(glm::vec3(size, -size, -size)),
		Vertex(glm::vec3(size, size, -size)),

		Vertex(glm::vec3(size, -size, size)), // Triangle 11
		Vertex(glm::vec3(size, -size, -size)),
		Vertex(glm::vec3(-size, -size, -size)),

		Vertex(glm::vec3(-size, -size, -size)), // Triangle 12
		Vertex(glm::vec3(-size, -size, size)),
		Vertex(glm::vec3(size, -size, size)),
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
