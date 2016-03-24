#include "Map.h"
#include <stdlib.h>
#include <ctime>

Map::Map()
{
	generateMap(TERRAIN_TYPE_WOS);	
}

Map::~Map()
{
	delete tileMap;
}

Tile* Map::getTileAt(int x, int y)
{
	return &tileMap[x][y];
}

void Map::generateMap(short terrainType)
{
	// TODO: Add addtional terrain algorithms. 
	memset(tileMap, 0, sizeof(tileMap));
	srand(time(NULL));
	short fillPercentage = rand()%10 + 37;
	for (int x = 0; x < MAP_WIDTH; x++)
	{
		for (int y = 0; y < MAP_HEIGHT; y++)
		{
			if (x == 0 || x == MAP_WIDTH - 1 || y == 0 || y == MAP_HEIGHT - 1)
				tileMap[x][y] = Tile{ TILE_IMPASSABLE, 0 };
			else
				tileMap[x][y] = (rand() % 100 < fillPercentage) ? Tile{ TILE_IMPASSABLE, 0 } : Tile{ TILE_EMPTY, 0 };
		}
	}
	smoothMap();

	// Setup vertex array
	vertices.setPrimitiveType(sf::Quads);
	vertices.resize(MAP_WIDTH * MAP_HEIGHT * 4);

	// Populate vertex array
	for (int x = 0; x < MAP_WIDTH; x++)
	{
		for (int y = 0; y < MAP_HEIGHT; y++)
		{
			sf::Vertex* quad = &vertices[(x + y  * MAP_WIDTH) * 4];

			quad[0].position = sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE);
			quad[1].position = sf::Vector2f((x + 1) * TILE_SIZE, y * TILE_SIZE);
			quad[2].position = sf::Vector2f((x + 1) * TILE_SIZE, (y + 1) * TILE_SIZE);
			quad[3].position = sf::Vector2f(x * TILE_SIZE, (y + 1) * TILE_SIZE);

			sf::Color quadColor = (tileMap[x][y].type == TILE_EMPTY) ? sf::Color::White : sf::Color::Black;
			quad[0].color = quadColor;
			quad[1].color = quadColor;
			quad[2].color = quadColor;
			quad[3].color = quadColor;
		}
	}
}

void Map::smoothMap()
{
	for (int x = 0; x < MAP_WIDTH; x++)
	{
		for (int y = 0; y < MAP_HEIGHT; y++)
		{
			int neighbourWallTiles = getSurroundingWallCount(x, y);
			if (neighbourWallTiles > 4)
				tileMap[x][y] = Tile{ TILE_IMPASSABLE , 0 };
			else if (neighbourWallTiles < 4)
				tileMap[x][y] = Tile{ TILE_EMPTY , 0 };
		}
	}
}

int Map::getSurroundingWallCount(int x, int y)
{
	int wallCount = 0;
	for (int neighbourX = x - 1; neighbourX <= x + 1; neighbourX++) {
		for (int neighbourY = y - 1; neighbourY <= y + 1; neighbourY++) {
			if (neighbourX >= 0 && neighbourX < MAP_WIDTH && neighbourY >= 0 && neighbourY < MAP_HEIGHT) {
				if (neighbourX != x || neighbourY != y) {
					wallCount += tileMap[neighbourX][neighbourY].type;
				}
			}
			else {
				wallCount++;
			}
		}
	}
	return wallCount;
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(vertices, states);
}