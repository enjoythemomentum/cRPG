#ifndef CLASSPLAYER_H
#define CLASSPLAYER_H

#include "classInventory.h"


class Player{
	private:
		int x;
		int y;
		int baseHealth; // base stats are the stats that the player starts with | can be modified by leveling up
		int baseAttack;
		int baseDefense;
		int baseIntelligence;
		int health; // current stats are the stats that the player has at the moment | can be modified by items
		int attack;
		int defense;
		int intelligence;
		bool inFight;
		bool inInteraction;
		char object;
		Inventory inventory;
	public:
		void spawnPlayer(int x, int y);
		bool getInInteraction();
		void setInInteraction(bool newInInteraction);
		void setInFight(bool newInFight);
		bool getInFight();
		int getX();
		int getY();
		void setPosition(int newX, int newY);
		int getBaseHealth();
		void setBaseHealth(int newBaseHealth);
		int getBaseIntelligence();
		void setBaseIntelligence(int newBaseIntelligence);
		int getBaseDefense();
		void setBaseDefense(int newBaseDefense);
		int getBaseAttack();
		void setBaseAttack(int newBaseAttack);
		int getHealth();
		void setHealth(int newHealth);
		void setIntelligence(int newIntelligence);
		int getIntelligence();
		void setDefense(int newDefense);
		int getDefense();	
		void setAttack(int newAttack);
		int getAttack();
		Inventory getInventory();
		void setInventory(Inventory newInventory);
		void addItem(int index, Item &newItem);
		void removeItem(int index);
		void removeItem(Item item);
		Item getItem(int index);	
		void movePlayer(char direction, Player &player);
		void printPlayerInfo(Player player);
		void updateStats();
		void checkChest(Player &player);
		void checkEnemy(Player &player);
		Player();
};

#endif
