#include "generatorMap.h"
#include "tools.h"
#include <cstdlib>
#include <iostream>
#include <string>

#include "messages.h"

#include "mapConstants.h"

#include "classPlayer.h"

using namespace std;

char map[_XMAPSIZE][_YMAPSIZE] = {0};

void generateChestPoints(int n) {

  for (int i = 0; i < n; i++) {
    int x = rand() % _XMAPSIZE;
    int y = rand() % _YMAPSIZE;
    map[x][y] = '=';
  }
}

void generateEnemyPoints(int n) {

  for (int i = 0; i < n; i++) {
    int x = rand() % _XMAPSIZE;
    int y = rand() % _YMAPSIZE;
    map[x][y] = '@';
  }
}

void generateMap(int seed) {

  message1 = "generating map " + to_string(_XMAPSIZE) + "x" +
             to_string(_YMAPSIZE) + " with seed: " + to_string(seed);
  message1 = textStyle(message1, 32);
  srand(seed);

  for (int i = 0; i < _XMAPSIZE; i++) {
    for (int j = 0; j < _YMAPSIZE; j++) {
      map[i][j] = '.';
    }
  }

  generateChestPoints(rand() % 3 + 1);
  generateEnemyPoints(rand() % 2 + 1);

  message2 = "map generated";
  message2 = textStyle(message2, 33);
}

void generateMap() { generateMap(time(NULL)); }

void printMap() {
  cout << endl;

  for (int i = 0; i < _XMAPSIZE; i++) {
    for (int j = 0; j < _YMAPSIZE; j++) {
      if (map[i][j] == '&') {
        cout << textStyle(map[i][j], 32) << " ";
      } else if (map[i][j] == '=') {
        cout << textStyle(map[i][j], 33) << " ";
      } else if (map[i][j] == '@') {
        cout << textStyle(map[i][j], 31) << " ";
      } else {
        cout << map[i][j] << " ";
      }
    }
    cout << endl;
  }
  cout << endl;
}

void printMapInRadius(Player player, int radius) {
  for (int i = 0; i < _XMAPSIZE; i++) {
    for (int j = 0; j < _YMAPSIZE; j++) {
      double distance =
          sqrt(pow(i - player.getX(), 2) + pow(j - player.getY(), 2));
      if (distance <= radius) {
        if (map[i][j] == '&') {
          cout << textStyle(map[i][j], 32) << " ";
        } else if (map[i][j] == '=') {
          cout << textStyle(map[i][j], 33) << " ";
        } else if (map[i][j] == '@') {
          cout << textStyle(map[i][j], 31) << " ";
        } else {
          cout << map[i][j] << " ";
        }
      } else {
        cout << "  ";
      }
    }
    cout << endl;
  }
}
