#pragma once

#include "BaseObject.h"
class Tile : public BaseObject
{
public:
	Tile();
	Tile(glm::vec3& pos, float size, glm::vec3& color);
	void initializeTile(glm::vec3& pos, float size, glm::vec3& color);
	void draw(const Camera& camera) override;
};

