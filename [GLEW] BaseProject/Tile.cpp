#include "Tile.h"


Tile::Tile(){}
Tile::Tile(glm::vec3& colorVal)
{
	m_color = colorVal;
}
// Generate Tiles
void Tile::initializeTile(glm::vec3& pos, float size)
{
	std::cout << "Zval-> " << pos.z << std::endl;
	Vertex vertices[] = 
	{
		// Triangle 1
		Vertex(glm::vec3( size / 2 + pos.x,  size / 2 + pos.y, pos.z)),
		Vertex(glm::vec3(-size / 2 + pos.x,  size / 2 + pos.y, pos.z)),
		Vertex(glm::vec3(-size / 2 + pos.x, -size / 2 + pos.y, pos.z)),

		// Triangle 2
		Vertex(glm::vec3(size / 2 + pos.x, size / 2 + pos.y, pos.z)),
		Vertex(glm::vec3(-size / 2 + pos.x, -size / 2 + pos.y, pos.z)),
		Vertex(glm::vec3( size / 2 + pos.x, -size / 2 + pos.y, pos.z))
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


