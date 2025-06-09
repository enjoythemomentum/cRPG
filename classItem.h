#ifndef CLASSITEM_H
#define CLASSITEM_H
#include <iostream>
using namespace std;
class Item{
	private:
		string name;
		string description;
		string rarity;
		float damage;
		float defense;
		float health;
		float intelligence;
		string type;

	enum type{
		weapon,
		armor,
		accessory,
		potion,
		food,
		quest
	};
	enum rarity{
		common,
		rare,
		epic,
		legendary,
		mythic
	};
	public:
		Item(); //default
    Item(string newName, string newDescription,
         int newDamage, int newDefense, int newHealth, int newIntelligence,
         string newRarity);

		void setName(string newName);
		string getName();
		void setDescription(string newDescription);
		string getDescription();
		void setDamage(float newDamage);
		float getDamage();
		void setDefense(float newDefense);
		float getDefense();
		void setHealth(float newHealth);
		float getHealth();
		void setRarity(string newRarity);
		string getRarity();
		void setIntelligence(float newIntelligence);
		float getIntelligence();
		void printItemStats();
		bool operator==(Item &other);
		bool operator!=(Item &other);
};

#endif
