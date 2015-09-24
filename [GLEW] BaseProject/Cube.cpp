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
	// Vertex Buffer
	Vertex vertices[] = 
	{
		// Triangle 1
		Vertex(glm::vec3( size,  size, size), glm::vec3(r, g, b)),
		Vertex(glm::vec3(-size,  size, size), glm::vec3(r, g, b)),
		Vertex(glm::vec3(-size, -size, size), glm::vec3(r, g, b)),

		// Triangle 2
		Vertex(glm::vec3(-size, -size, size), glm::vec3(r, g, b)),
		Vertex(glm::vec3( size, -size, size), glm::vec3(r, g, b)),
		Vertex(glm::vec3( size,  size, size), glm::vec3(r, g, b)),
		
		// Triangle 3
		Vertex(glm::vec3( size,  size,  size), glm::vec3(r, g, b)),
		Vertex(glm::vec3( size, -size,  size), glm::vec3(r, g, b)),
		Vertex(glm::vec3( size, -size, -size), glm::vec3(r, g, b)),

		// Triangle 4
		Vertex(glm::vec3(size, -size, -size), glm::vec3(r, g, b)),
		Vertex(glm::vec3(size,  size, -size), glm::vec3(r, g, b)),
		Vertex(glm::vec3(size,  size,  size), glm::vec3(r, g, b)),

		// Triangle 5
		Vertex(glm::vec3( size, size,  size), glm::vec3(r, g, b)),
		Vertex(glm::vec3( size, size, -size), glm::vec3(r, g, b)),
		Vertex(glm::vec3(-size, size, -size), glm::vec3(r, g, b)),

		// Triangle 6
		Vertex(glm::vec3(-size, size, -size), glm::vec3(r, g, b)),
		Vertex(glm::vec3(-size, size,  size), glm::vec3(r, g, b)),
		Vertex(glm::vec3( size, size,  size), glm::vec3(r, g, b)),

		// Triangle 7
		Vertex(glm::vec3(-size,  size,  size), glm::vec3(r, g, b)),
		Vertex(glm::vec3(-size, -size,  size), glm::vec3(r, g, b)),
		Vertex(glm::vec3(-size, -size, -size), glm::vec3(r, g, b)),

		// Triangle 8
		Vertex(glm::vec3(-size, -size, -size), glm::vec3(r, g, b)),
		Vertex(glm::vec3(-size,  size, -size), glm::vec3(r, g, b)),
		Vertex(glm::vec3(-size,  size,  size), glm::vec3(r, g, b)),

		// Trianlge 9
		Vertex(glm::vec3( size,  size, -size), glm::vec3(r, g, b)),
		Vertex(glm::vec3(-size,  size, -size), glm::vec3(r, g, b)),
		Vertex(glm::vec3(-size, -size, -size), glm::vec3(r, g, b)),

		// Triangle 10
		Vertex(glm::vec3(-size, -size, -size), glm::vec3(r, g, b)),
		Vertex(glm::vec3( size, -size, -size), glm::vec3(r, g, b)),
		Vertex(glm::vec3( size,  size, -size), glm::vec3(r, g, b)),

		// Triangle 11
		Vertex(glm::vec3( size, -size,  size), glm::vec3(r, g, b)),
		Vertex(glm::vec3( size, -size, -size), glm::vec3(r, g, b)),
		Vertex(glm::vec3(-size, -size, -size), glm::vec3(r, g, b)),

		// Triangle 12
		Vertex(glm::vec3(-size, -size, -size), glm::vec3(r, g, b)),
		Vertex(glm::vec3(-size, -size,  size), glm::vec3(r, g, b)),
		Vertex(glm::vec3( size, -size,  size), glm::vec3(r, g, b))
	};

	// Initialize
	m_mesh.init(vertices, sizeof(vertices)/sizeof(vertices[0]));
	m_shader.init((char*)"res/basicShader");
}

void Cube::draw(const Camera& camera)
{
	m_shader.bind(); // binds the shader to the mesh
	m_shader.update(m_transform, camera); // updates the shader 
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
