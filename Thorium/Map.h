#pragma once
#include "SFML\Graphics.hpp"

#define TILE_EMPTY			0
#define TILE_IMPASSABLE		1

#define TILE_OBSCURING		0x01
#define TILE_ON_FIRE		0x02
#define TILE_RIVER_BED		0x04
#define TILE_ROUGH_TERRAIN	0x08
#define TILE_SMALL_WATER	0x10
#define TILE_LARGE_WATER	0x20

#define TERRAIN_TYPE_WOS	0
#define TERRAIN_TYPE_HC		1
#define TERRAIN_TYPE_ROUGH	2

#define MAP_WIDTH	48
#define MAP_HEIGHT	48

#define TILE_SIZE	8

struct Tile 
{
	short type;
	unsigned char flags;
};

class Map : public sf::Drawable, public sf::Transformable
{
private:
	void smoothMap();
	int getSurroundingWallCount(int x, int y);
	Tile tileMap[MAP_WIDTH][MAP_HEIGHT];
	sf::VertexArray vertices;
	sf::Texture texture;
public:
	Map();
	~Map();
	Tile* getTileAt(int x, int y);
	void generateMap(short terrainType);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

