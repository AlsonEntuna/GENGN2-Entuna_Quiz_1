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
	    do
		{
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
        setX(xVal);
		setY(yVal);
		setZ(zVal);
        squareSize = sideHeight;
    }
	else squareSize = -1;

	for (int i = 0; i < boxContent.size(); i++)
	{
		for (int j = 0; j < boxContent[i].size(); j++)
		{
			switch (boxContent[i][j])
			{
				// Set the Color via Constructor
				case 'l': m_Tiles.push_back(new Tile(glm::vec3(1.0f, 1.0f, 1.0f))); break;
				case 'd': m_Tiles.push_back(new Tile(glm::vec3(0.5f, 0.5f, 0.5f))); break;
				case 'r': m_Tiles.push_back(new Tile(glm::vec3(1.0f, 0.0f, 0.0f))); break;
				case 'g': m_Tiles.push_back(new Tile(glm::vec3(0.0f, 1.0f, 0.0f))); break;
				case 'b': m_Tiles.push_back(new Tile(glm::vec3(0.0f, 0.0f, 1.0f))); break;
				case 'y': m_Tiles.push_back(new Tile(glm::vec3(1.0f, 1.0f, 0.0f))); break;
			}

			// Initialize Position of the tile
			m_Tiles.back()->initializeTile(glm::vec3(getX() + j * squareSize, getY() + (boxContent.size() - i - 1) * squareSize, getZ()), squareSize);
		}
	}

	std::cout << "zVal: " << getZ() << std::endl;
}

void Board::draw(const Camera& camera)
{
	// Draw the tiles 
	for each (Tile* var in m_Tiles)
		var->draw(camera);

	/*for (int i = 0; i < m_Tiles.size(); i++)
		m_Tiles[i]->draw(camera);*/
}

void Board::drawSquare(glm::vec3& pos, float size)
{
	//m_Tiles.push_back(new Tile(pos, size));	
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
