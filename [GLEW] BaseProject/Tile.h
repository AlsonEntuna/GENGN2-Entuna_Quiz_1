#pragma once

#include "BaseObject.h"
class Tile : public BaseObject
{
public:
	Tile();
	Tile(glm::vec3& colorVal);
	void initializeTile(glm::vec3& pos, float size);
	void draw(const Camera& camera) override;
};

