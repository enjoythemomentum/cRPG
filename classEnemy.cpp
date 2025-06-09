#include "classEnemy.h"
#include "classChest.h"
#include "classInventory.h"
#include "classPlayer.h"
#include "combatHandler.h"
#include "generatorMap.h"
#include "items.h"
#include "messages.h"
#include "tools.h"
#include <cmath>
#include <iostream>

using namespace std;

int Enemy::getX() { return x; }

int Enemy::getY() { return y; }

void Enemy::setPosition(int newX, int newY) {
  x = newX;
  y = newY;
}

void Enemy::printInventory() { inventory.printInventory(); }

void Enemy::setName(string newName) { name = newName; }

void Enemy::setDescription(string newDescription) {
  description = newDescription;
}

string Enemy::getName() { return name; }

string Enemy::getDescription() { return description; }

int Enemy::getHealth() { return health; }
void Enemy::setHealth(int newHealth) { health = newHealth; }
void Enemy::addHealth(int addHealth) { health += addHealth; }
Inventory Enemy::getInventory() { return inventory; }
void Enemy::setInventory(Inventory newInventory) { inventory = newInventory; }
void Enemy::addItem(int index, Item newItem) {
  inventory.addItem(index, newItem);
}

void Enemy::printInfo() {
  cout << "[ E N E M Y ] " << getName() << endl;
  cout << "Health: " << getHealth() << endl;
  cout << "Position: "
       << "X: " << getX() << "Y: " << getY() << endl;
  cout << endl;
}

Enemy::Enemy() {
  name = "Enemy";
  description = "Enemy";
  health = 10;
}
