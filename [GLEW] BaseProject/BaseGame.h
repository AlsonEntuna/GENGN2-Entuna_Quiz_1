#ifndef BASEGAME_H
#define	BASEGAME_H

#include <math.h>
#include "GL\glew.h"
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Camera.h"
class BaseGame
{
    public:
		BaseGame(int width,int height,char title[]);
		void initialization();
		void eventPoll();
		bool isRunning();
        void start();
    protected:
        void clear();
		void display();
		bool isUPPressed();
		bool isDOWNPressed();
		bool isLEFTPressed();
		bool isRIGHTPressed();
		bool isSPressed();
		bool isWPressed();
        bool isSpacePressed();

        virtual void update() = 0;
        virtual void draw() = 0;

		// Camera
		Camera* camera = new Camera(glm::vec3(0, 0, 0), 70.0f, 400.0f / 300.0f, 0.01f, 1000.0f);

	private:
		sf::Window window;
		bool running;
		void gluPerspectiveCompat( GLdouble fovY, GLdouble aspect,
			GLdouble zNear, GLdouble zFar );
		void resizeWindow(unsigned int width,unsigned int height);
};

#endif /* BASEGAME_H */
