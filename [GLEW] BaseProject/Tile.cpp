#include "Tile.h"


Tile::Tile(){}
Tile::Tile(glm::vec3& pos, float size, glm::vec3& color)
{
	initializeTile(pos, size, color);
}

// Generate Tiles
void Tile::initializeTile(glm::vec3& pos, float size, glm::vec3& color)
{
	// Initialize Position
	m_transform.GetPos()->x = pos.x;
	m_transform.GetPos()->y = pos.y;
	m_transform.GetPos()->z = pos.z;

	// Initialize Colors
	m_color.x = color.x;
	m_color.y = color.y;
	m_color.z = color.z;

	Vertex vertices[] = 
	{
		Vertex(glm::vec3( size,  size, -size)),
		Vertex(glm::vec3( size,  size, -size)),
		Vertex(glm::vec3(-size, -size, -size)),

		Vertex(glm::vec3( size,  size, -size)),
		Vertex(glm::vec3(-size, -size, -size)),
		Vertex(glm::vec3( size, -size, -size))
	};

	// Initialize mesh
	m_mesh.init(vertices, sizeof(vertices) / sizeof(vertices[0]));
	m_shader.init((char*)"res/basicShader");
}

void Tile::draw(const Camera& camera)
{
	m_shader.bind(); // bind shader
	m_shader.update(m_transform, camera, m_color); // update shader
	m_mesh.draw(); // draw mesh
}


