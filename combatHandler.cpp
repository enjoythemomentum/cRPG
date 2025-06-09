#include <iostream>

#include "classEnemy.h"
#include "classPlayer.h"
#include "combatHandler.h"
#include "tools.h"
#include <cstdlib>

using namespace std;

void printPlayerHealthBar(Player &player) {
  for (int i = 0; i < player.getHealth() / 2; i++) {
    cout << "🀫";
  }
}

void printEnemyHealthBar(Enemy &enemy) {
  for (int i = 0; i < enemy.getHealth() / 2; i++) {
    cout << "🀫";
  }
}

void printFightScreen(Player &player, Enemy &enemy) {
  cout << "Player"
       << "\t \t \t" << enemy.getName() << endl;
  cout << "HP: ";
  printPlayerHealthBar(player);

  cout << "\t \t";

  cout << "HP: ";
  printEnemyHealthBar(enemy);
  cout << endl << endl;
  cout << "[Choose weapon to use] Inventory: " << endl;
}

int firstTurn() {
  srand(static_cast<unsigned int>(time(nullptr)));
  return rand() % 2;
}

void fight(Player &player, Enemy &enemy) {
  int activeIndex = 0;
  int invSize = player.getInventory().getSize();
  char _input;
  bool _state = true;
  string _message;

  int whosTurn = firstTurn(); // 0 - player; 1 - enemy

  while (_state) {
    clearScreen();
    printFightScreen(player, enemy);
    if (!_message.empty()) {
      cout << _message << endl;
      _message.clear();
    }

    for (int i = 0; i < invSize; ++i) {
      cout << i << ". ";
      if (i == activeIndex) {
        cout << textStyle(textStyle(player.getItem(i).getName(), 47), 30);
      } else {
        cout << player.getItem(i).getName();
      }
      cout << endl;
    }

    cout << "It is " << (whosTurn == 0 ? "player's" : "enemy's") << " turn."
         << endl;

    if (whosTurn == 0) {
      cin >> _input;
      switch (_input) {
      case 's':
        activeIndex = (activeIndex + 1) % invSize;
        break;
      case 'w':
        activeIndex = (activeIndex - 1 + invSize) % invSize;
        break;
      case 'e':
        // Assume there is some logic here to use the item at activeIndex
        whosTurn = 1;
        break;
      case 'q':
        _state = false;
        break;
      default:
        _message = "Wrong input";
        break;
      }
    } else {
      // Enemy's turn logic should be implemented here
      whosTurn = 0;
    }
  }
}
