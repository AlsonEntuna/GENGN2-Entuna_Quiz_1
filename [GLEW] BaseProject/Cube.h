#ifndef CUBE_H
#define	CUBE_H


#include "BaseObject.h"
//#include <SFML/OpenGL.hpp>

class Cube: public BaseObject
{
    public:
        Cube();
		Cube(float r, float g, float b, float size);
        void init(float r, float g, float b, float size);
        void draw(const Camera& camera) override;

		// Translations
        void moveUP();
        void moveDOWN();
        void moveLEFT();
        void moveRIGHT();
	private:
		float rotate;
        float cubeSize;
        float tileSize;
};

#endif
