#include <iostream>
#include "Board.h"
#include "Cube.h"
#include "BaseGame.h"
#include "Tile.h"

const int DIRECTION_UP      = 1;
const int DIRECTION_DOWN    = 2;
const int DIRECTION_LEFT    = 3;
const int DIRECTION_RIGHT   = 4;

const float START_X         = 1.5f;
const float START_Y         = 4.0f;
const float START_Z         = 11.0f;
const float SQUARE_WIDTH    = 0.8f;

class Slide: public BaseGame
{
    private:
        Board board;
        Cube cube;
        int animationTime;
        bool isTriggered;
        int direction;
    public:
        Slide(int width,int height,char title[]):
        BaseGame(width, height, title)
		{
			// Instantiate Board
            board.init((char*)"res/slide.map", SQUARE_WIDTH, -START_X, -START_Y, -START_Z);
			// Instantiate Cube
			cube.init(1.0f, 1.0f, 0.0f, SQUARE_WIDTH - 0.1f);
			// Set Position Cube
			cube.setX(-START_X + 0.05f);
			cube.setY(-START_Y + 0.1f);
			cube.setZ(-START_Z + SQUARE_WIDTH / 2 + 0.05f);

            isTriggered = false;
            direction = 0;
            animationTime = 0;
        }
    protected:
        void update()
		{
            controlls();
            moveCube();
            if(direction>0&&animationTime < 1)
                nextAction();
        }

		
        void draw()
		{
            board.draw(*camera);
            cube.draw(*camera);
        }

        void controlls()
		{
            if(animationTime<1)
			{
                if(isUPPressed())
				{
                    if(!isTriggered)
					{
                        direction = DIRECTION_UP;
                        if(isNextMovementSafe())
                            animationTime = 20;
                        isTriggered = true;
                    }
                }
				else if(isDOWNPressed())
				{
                    if(!isTriggered)
					{
                        direction = DIRECTION_DOWN;
                        if(isNextMovementSafe())
                            animationTime = 20;
                        isTriggered = true;
                    }
		        }
				else if(isLEFTPressed())
				{
                    if(!isTriggered)
					{
                        direction = DIRECTION_LEFT;
                        if(isNextMovementSafe())
                            animationTime = 20;
                        isTriggered = true;
                    }
                }
				else if(isRIGHTPressed())
				{
                    if(!isTriggered)
					{
                        direction = DIRECTION_RIGHT;
                        if(isNextMovementSafe())
                            animationTime = 20;
                        isTriggered = true;
                    }
                }
				else if(isSpacePressed())
				{
                    if(!isTriggered)
                        isTriggered = true;
                }
				else if(isTriggered)
                    isTriggered = false;
            }
        }

        void moveCube()
		{
            if(animationTime > 0)
			{
                animationTime--;
                switch(direction)
				{
                    case DIRECTION_UP:
                        cube.setY(cube.getY()+SQUARE_WIDTH/20);
                        break;
                    case DIRECTION_DOWN:
                        cube.setY(cube.getY()-SQUARE_WIDTH/20);
                        break;
                    case DIRECTION_LEFT:
                        cube.setX(cube.getX()-SQUARE_WIDTH/20);
                        break;
                    case DIRECTION_RIGHT:
                        cube.setX(cube.getX()+SQUARE_WIDTH/20);
                        break;
                }
            }
        }

        bool isNextMovementSafe()
		{
            char nextChar;
            int newX = (cube.getX()+START_X)/SQUARE_WIDTH;            
            int newY = (cube.getY()+START_Y)/SQUARE_WIDTH;
            switch(direction)
			{
                case DIRECTION_UP:newY++;break;
                case DIRECTION_DOWN:newY--;break;
                case DIRECTION_LEFT:newX--;break;
                case DIRECTION_RIGHT:newX++;break;
            }

            if(newY>=0&&newY<board.getHeight()&&
                    newX>=0&&newX<board.getWidth())
			{
                nextChar=board.getTileType(newX,newY);
                if(nextChar!='r')
                    return true;
            }
            return false;
        }

        void nextAction()
		{
            int xSpace = (cube.getX()+START_X)/SQUARE_WIDTH;
            int ySpace = (cube.getY()+START_Y)/SQUARE_WIDTH;
            if(board.getTileType(xSpace,ySpace) == 'b')
			{
                if(isNextMovementSafe())
				{
                    switch(direction)
					{
                        case DIRECTION_UP:{animationTime = 20;}break;
                        case DIRECTION_DOWN:{animationTime = 20;}break;
                        case DIRECTION_LEFT:{animationTime = 20;}break;
                        case DIRECTION_RIGHT:{animationTime = 20;}break;
                    }
                }
				else direction = 0;
            }
			else if(board.getTileType(xSpace,ySpace) =='y')
			{
                //std::cout << "WIN!";
                cube.setX(-START_X+0.05f);
                cube.setY(-START_Y+0.1f);
                direction = 0;
            }
			else direction = 0;
        }
};

int main()
{
    char title[] = "[GENGN2] Entuna Quiz 1";
    Slide application(600, 800, title);
    application.start();
    return 0;
}
