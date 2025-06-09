#ifndef CLASSENEMY_H

#define CLASSENEMY_H

#include "classInventory.h"

class Enemy{
	private:
		string name;
		string description;
		int x;
		int y;
		int health;
		int damage;
		Inventory inventory;
	public:
		Enemy();
		int getX();		
		int getY();
		void setPosition(int newX, int newY);
		void printInventory();
		void setName(string newName);
		void setDescription(string newDescription);
		string getName();
		string getDescription();
		int getHealth();
    void setHealth(int newHealth);
		void addHealth(int addHealth);
		Inventory getInventory();
		void setInventory(Inventory newInventory);
    void printInfo();
    void addItem(int index, Item newItem);
};


#endif
