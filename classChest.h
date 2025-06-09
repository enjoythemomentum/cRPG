#ifndef CHEST_H
#define CHEST_H

#include <iostream>
#include "classItem.h"
#include "items.h"
#include "classPlayer.h"

using namespace std;

class Chest{
	private:
		string name;
		Item item;
    Inventory storage;
	public:
		Chest();
		Item getItem();
		void setName(string name);
		string getName();
		int openChest(Player &player);
		void setItem(Item item);
    Inventory getStorage();
    void setStorage(Inventory newStorage);


};

#endif
