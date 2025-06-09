#include "classPlayer.h"
#include "classChest.h"
#include "classEnemy.h"
#include "classInventory.h"
#include "combatHandler.h"
#include "generatorMap.h"
#include "items.h"
#include "messages.h"
#include "tools.h"
#include <cmath>
#include <iostream>

using namespace std;

bool Player::getInInteraction() { return inInteraction; }
void Player::setInInteraction(bool newInInteraction) {
  inInteraction = newInInteraction;
}
void Player::setInFight(bool newInFight) { inFight = newInFight; }
bool Player::getInFight() { return inFight; }
int Player::getX() { return x; }

int Player::getY() { return y; }

void Player::setPosition(int newX, int newY) {
  x = newX;
  y = newY;
}

int Player::getBaseHealth() { return baseHealth; }
void Player::setBaseHealth(int newBaseHealth) { baseHealth = newBaseHealth; }
int Player::getBaseIntelligence() { return baseIntelligence; }

void Player::setBaseIntelligence(int newBaseIntelligence) {
  baseIntelligence = newBaseIntelligence;
}
int Player::getBaseDefense() { return baseDefense; }
void Player::setBaseDefense(int newBaseDefense) {
  baseDefense = newBaseDefense;
}
int Player::getBaseAttack() { return baseAttack; }
void Player::setBaseAttack(int newBaseAttack) { baseAttack = newBaseAttack; }
int Player::getHealth() { return health; }
void Player::setHealth(int newHealth) { health = newHealth; }
void Player::setIntelligence(int newIntelligence) {
  intelligence = newIntelligence;
}
int Player::getIntelligence() { return intelligence; }
void Player::setDefense(int newDefense) { defense = newDefense; }
int Player::getDefense() { return defense; }
void Player::setAttack(int newAttack) { attack = newAttack; }
int Player::getAttack() { return attack; }
Inventory Player::getInventory() { return inventory; }
void Player::setInventory(Inventory newInventory) { inventory = newInventory; }
void Player::addItem(int index, Item &newItem) {
  inventory.addItem(index, newItem);
}
void Player::removeItem(int index) { inventory.removeItem(index); }
void Player::removeItem(Item item) { inventory.removeItem(item); }
Item Player::getItem(int index) { return inventory.getItem(index); }
void Player::spawnPlayer(int x, int y) { map[x][y] = '&'; }

void Player::checkChest(Player &player) {
  if (object == '=') {
    message1 = textStyle(message1, 34);
    clearScreen();
    Chest chest;
    chest.openChest(player);
    updateStats();
  }
}

void Player::checkEnemy(Player &player) {
  if (object == '@') {
    Enemy skeleton;
    skeleton.setName("Skeleton");
    skeleton.setHealth(10);
    fight(player, skeleton);
    player.setInInteraction(true);
  }
}

void Player::movePlayer(char direction, Player &player) {
  int currentX = player.getX();
  int currentY = player.getY();

  map[currentX][currentY] = '.';
  int newX = currentX, newY = currentY;

  switch (direction) {
  case 'w':
    newX = currentX - 1;
    break;
  case 's':
    newX = currentX + 1;
    break;
  case 'a':
    newY = currentY - 1;
    break;
  case 'd':
    newY = currentY + 1;
    break;
  default:
    return;
  }

  if (newX >= 0 && newX < _XMAPSIZE && newY >= 0 && newY < _YMAPSIZE) {
    object = map[newX][newY];
    map[newX][newY] = '&';
    player.setPosition(newX, newY);
    checkChest(player);
    checkEnemy(player);
  } else {
    message1 = "Invalid move | Out of bounds";
    message1 = textStyle(message1, 31);
    player.setPosition(currentX, currentY);
    map[currentX][currentY] = '&';
  }
}
void Player::printPlayerInfo(Player player) {
  cout << "Player: " << endl;
  cout << endl;
  cout << textStyle("♥ Health: ", 92) << getHealth() << endl;
  cout << textStyle("➲ Attack: ", 91) << getAttack() << endl;
  cout << textStyle("✎ Intelligence: ", 34) << getIntelligence() << endl;
  cout << textStyle("♜ Defense: ", 36) << getDefense() << endl;
  cout << endl;
  cout << "Inventory: " << endl;
  getInventory().printInventory();
  cout << endl;
}
// updates players stats based on items in inventory (maybe perks dunno)
void Player::updateStats() {
  int totalHealth = getBaseHealth();
  int totalAttack = getBaseAttack();
  int totalDefense = getBaseDefense();
  int totalIntelligence = getBaseIntelligence();
  for (int i = 0; i < getInventory().getSize(); i++) {
    Item item = getItem(i);

    totalHealth += item.getHealth();
    totalAttack += item.getDamage();
    totalDefense += item.getDefense();
    totalIntelligence += item.getIntelligence();
  }
  setHealth(totalHealth);
  setAttack(totalAttack);
  setDefense(totalDefense);
  setIntelligence(totalIntelligence);
}

Player::Player() {
  x = 0;
  y = 0;
  baseHealth = 10;
  baseAttack = 1;
  baseDefense = 1;
  baseIntelligence = 2;
  health = baseHealth;
  attack = baseAttack;
  defense = baseDefense;
  intelligence = baseIntelligence;
  inFight = false;
  inInteraction = false;
  addItem(0, allItems["Fist"]);
}
