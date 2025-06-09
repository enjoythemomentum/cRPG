#ifndef CLASSINVENTORY_H_
#define CLASSINVENTORY_H_

#include "classItem.h"
#include "items.h"

#define _INVENTORYSIZE 6

using namespace std;

class Inventory{
	private:

		Item items[_INVENTORYSIZE];
	public:
		Inventory();
		Item getItem(int index);
    int getSize();
		void addItem(int index, Item item);
		void printInventory();
		void removeItem(int index);
		void removeItem(Item item);
		bool isEmpty(int index);
		bool contains(Item item);
};

#endif /* CLASSINVENTORY_H_ */
