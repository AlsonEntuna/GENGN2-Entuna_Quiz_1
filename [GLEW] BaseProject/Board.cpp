#include "Board.h"

Board::Board()
{
}

Board::Board(char file[],float sideHeight,float xVal,float yVal,float zVal)
{
	init(file,sideHeight,xVal,yVal,zVal);
}

void Board::init(char file[],float sideHeight,float xVal,float yVal,float zVal)
{
	std::ifstream in;
	in.open(file);
    std::vector<char> line;
	if(!in.fail())
	{
	    char c;
	    do{
		    c = in.get();
            if(c=='\n'||c==-1)
			{
                if(line.size() > 0)
				{
                    boxContent.push_back(line);
                    line.erase(line.begin(),line.end());
                }
            }
			else line.push_back(c);
	    }
		while(in.good());
        x = xVal;
        y = yVal;
        z = zVal;
        squareSize = sideHeight;
    }
	else squareSize = -1;
}

void Board::draw(const Camera& camera)
{
	/*glPushMatrix();
	for(int i = 0;i < boxContent.size(); i++)
	{
	    for(int j=0;j<boxContent[i].size();j++)
		{
            switch(boxContent[i][j])
			{
                case 'l':glColor3f(1.0f, 1.0f, 1.0f);break;
                case 'd':glColor3f(0.5f, 0.5f, 0.5f);break;
                case 'r':glColor3f(1.0f, 0.0f, 0.0f);break;
                case 'g':glColor3f(0.0f, 1.0f, 0.0f);break;
                case 'b':glColor3f(0.0f, 0.0f, 1.0f);break;
                case 'y':glColor3f(1.0f, 1.0f, 0.0f);break;
            }
			drawSquare(x+j*squareSize,y+(boxContent.size()-i-1)*squareSize);
		}
	}
	glPopMatrix();*/

	glm::vec3 newColor;
	for (int i = 0; i < boxContent.size(); i++)
	{
		for (int j = 0; j < boxContent[i].size(); j++)
		{
			//switch (boxContent[i][j])
			//{
			//	case 'l': drawSquare(1.0f, 1.0f, 1.0f, squareSize); break;
			//	case 'd': drawSquare(0.5f, 0.5f, 0.5f, squareSize); break;
			//	case 'r': drawSquare(1.0f, 0.0f, 0.0f, squareSize); break;
			//	case 'g': drawSquare(0.0f, 1.0f, 0.0f, squareSize); break;
			//	case 'b': drawSquare(0.0f, 0.0f, 1.0f, squareSize); break;
			//	case 'y': drawSquare(1.0f, 1.0f, 0.0f, squareSize); break;
			//}

			//// Initialize transform per tile
			//m_Tiles.back()->setX(getX() + j * squareSize);
			//m_Tiles.back()->setY(getY() + (boxContent.size() - i + 1) * squareSize);
			//m_Tiles.back()->setZ(getZ());
		}
	}

	// Draw the tiles 
	//for each (Tile* var in m_Tiles)
		//var->draw(camera);
}

void Board::drawSquare(glm::vec3& pos, float size, glm::vec3& color)
{
	//m_Tiles.push_back(new Tile(glm, size/2 +));
	
}

bool Board::isInitProperly()
{
    return (boxContent.size() > 0);
}

char Board::getTileType(int xSpace,int ySpace)
{
    return boxContent[getHeight()-1-ySpace][xSpace];
}

float Board::getBlockWidth()
{
    return squareSize;
}

float Board::getTopY(){return (boxContent.size()-1)*squareSize+y;}

int Board::getWidth()
{
    return boxContent[0].size();
}

int Board::getHeight()
{
    return boxContent.size();
}

void Board::emptyBoard()
{
    boxContent.erase(boxContent.begin(),boxContent.end());
}
