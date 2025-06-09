#ifndef COMBAT_HANDLER_H
#define COMBAT_HANDLER_H

#include "classPlayer.h"
#include "classEnemy.h"

void printPlayerHealthBar(Player &player);
void printenemyhealthbar(Enemy &enemy);
void printFightScreen(Player &player, Enemy &enemy);
void fight(Player &player, Enemy &enemy);

#endif
