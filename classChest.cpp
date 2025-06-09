#include "classChest.h"
#include "classItem.h"
#include "classPlayer.h"
#include "generatorMap.h"
#include "items.h"
#include "messages.h"
#include "tools.h"
#include <iostream>

Chest::Chest() { // Test
  name = "Chest";
  item = allItems["Fire Sword"];
};

Item Chest::getItem() { return item; };

void Chest::setItem(Item item) { item = item; };

void Chest::setName(string name) { name = name; };

string Chest::getName() { return name; };

Inventory Chest::getStorage() { return storage; }

void Chest::setStorage(Inventory newStorage) { storage = newStorage; }

int Chest::openChest(Player &player) {
  int activeIndex = 0;
  int invSize = player.getInventory().getSize();
  char _input;
  bool _state = true;
  string _message = "";
  do {
    clearScreen();
    cout << "-----  C R A T E  -----" << endl;
    cout << endl;
    cout << "  " << getItem().getRarity() << " " << getItem().getName() << endl;
    cout << "  " << getItem().getDescription() << endl;
    getItem().printItemStats();
    cout << endl;
    cout << "-----------------------" << endl;
    cout << endl;
    cout << "Choose slot to equip: " << endl;
    cout << "   [W] or [S] to navigate." << endl;
    cout << "   [E] to equip." << endl;
    cout << textStyle("   [Q] to exit.", 31) << endl;
    cout << endl;

    cout << _message << endl;
    _message = "";

    for (int i = 0; i < invSize; i++) {
      if (i == activeIndex) {
        cout << i << ". "
             << textStyle(textStyle(player.getItem(i).getName(), 47), 30)
             << endl;
      } else {
        cout << i << ". " << player.getItem(i).getName() << endl;
      }
    }

    cout << endl << "Active index: " << activeIndex << endl;

    cin >> _input;
    switch (_input) {
    case 's':
      activeIndex++;
      if (activeIndex > invSize - 1) {
        activeIndex = 0;
      }
      break;
    case 'w':
      activeIndex--;
      if (activeIndex < 0) {
        activeIndex = invSize - 1;
      }
      break;
    case 'e':
      if (activeIndex == 0) {
        _message = "Cannot set item to slot O";
        break;
      }
      player.addItem(activeIndex, item);
      message1 =
          textStyle(item.getName() + " has been added to your inventory!", 35);
      message2 = textStyle("Nicely done!", 36);
      _state = false;
      break; // - _ -
    case 'q':
      _state = false;
    default:
      _message = "Wrong input";
      break;
    }
  } while (_state);
  return 0;
}
