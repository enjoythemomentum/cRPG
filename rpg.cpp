#include <ctime>
#include <iostream>
#include <string>

#include "generatorMap.h"

#include "classEnemy.h"
#include "classPlayer.h"
#include "items.h"

#include "messages.h"

#include "tools.h"

#include "mapConstants.h"

using namespace std;

Player player;

int main() {

  generateMap();
  player.spawnPlayer(0, 0);
  bool state = true;

  char input;

  // get current time
  time_t now = time(0);

  cout << endl;
  do {
    clearScreen();
    // printMap();
    printMapInRadius(player, player.getIntelligence());

    cout << endl << message1;
    cout << endl << message2 << endl;
    message1 = "";
    message2 = "";
    cout << endl;
    player.printPlayerInfo(player);

    cout << "Move: ";
    cin >> input;
    switch (input) {
    case 'w':
    case 's':
    case 'a':
    case 'd':
      player.movePlayer(input, player);
      break;
    case 'q':
      state = false;
      break;
    case 'c':
      player.addItem(5, allItems["Health Potion"]);
      player.updateStats();
      break;
    default:
      message1 = "Invalid input " + to_string(input) + " is not a valid input";
      message1 = textStyle(message1, 31);
      break;
    }

  } while (state);

  clearScreen();
  cout << "Game Over" << endl;
  cout << "You played for " << difftime(time(0), now) << " seconds" << endl;

  return 0;
}
