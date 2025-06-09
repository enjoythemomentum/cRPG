#include "classItem.h"
#include "tools.h"
#include <iostream>


using namespace std;
		Item::Item(){
			name = "";
			description = "";
			damage = 0;
			defense = 0;
			health = 0;
			intelligence = 0;
      rarity = "";
		}

    Item::Item(string newName, string newDescription,int newDamage, int newDefense, int newHealth, int newIntelligence,string newRarity){
      name = newName;
      description = newDescription;
      damage = newDamage;
      defense = newDefense;
      health = newHealth;
      intelligence = newIntelligence;
      rarity = newRarity;
    };

		void Item::setName(string newName) { name = newName; }
		string Item::getName() { return name; }

		void Item::setDescription(string newDescription) { description = newDescription; }
		string Item::getDescription() { return description; }

		void Item::setDamage(float newDamage) { damage = newDamage; }
		float Item::getDamage() { return damage; }

		void Item::setDefense(float newDefense) { defense = newDefense; }
		float Item::getDefense() { return defense; }

		void Item::setHealth(float newHealth) { health = newHealth; }
		float Item::getHealth() { return health; }

		void Item::setRarity(string newRarity) { rarity = newRarity; }
		string Item::getRarity() { return rarity; }

		void Item::setIntelligence(float newIntelligence) { intelligence = newIntelligence; }
		float Item::getIntelligence() { return intelligence; }

		void Item::printItemStats(){
			cout << textStyle("> ♥ Health: ", 92) << getHealth() << endl;
			cout << textStyle("> ➲ Damage: ", 91) << getDamage() << endl;
			cout << textStyle("> ✎ Intelligence: ", 34) << getIntelligence() << endl;
			cout << textStyle("> ♜ Defense: ",36) << getDefense() << endl;
		}

		bool Item::operator==(Item &other){
			if(name == other.getName()
					&& description == other.getDescription()
					&& damage == other.getDamage()
					&& defense == other.getDefense()
					&& health == other.getHealth()
					&& intelligence == other.getIntelligence()
					&& rarity == other.getRarity()){
				return true;
			}
			else{
				return false;
			}
		}
		bool Item::operator!=(Item &other){
			if(name == other.getName()
					&& description == other.getDescription()
					&& damage == other.getDamage()
					&& defense == other.getDefense()
					&& health == other.getHealth()
					&& intelligence == other.getIntelligence()
					&& rarity == other.getRarity()){
				return false;
			}
			else{
				return true;
			}
		}
