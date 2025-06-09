#ifndef GENERATORMAP_H
#define GENERATORMAP_H
#include "mapConstants.h"

#include "classPlayer.h"

extern char map[_XMAPSIZE][_YMAPSIZE];

void generateChestPoints(int n);

void generateEnemyPoints(int n);

void generateMap(int seed);

void generateMap();

void printMap();

void printMapInRadius(Player player, int radius);

#endif
