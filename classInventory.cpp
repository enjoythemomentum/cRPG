#include <iostream>
#include "classInventory.h"

#define _INVENTORYSIZE 6

using namespace std;

		Inventory::Inventory(){
			for(int i = 0; i < _INVENTORYSIZE; i++){
				items[i] = allItems["Empty"];
			}
		}

    int Inventory::getSize(){
        return _INVENTORYSIZE;
    }

		Item Inventory::getItem(int index){
			return items[index];
		}
		void Inventory::addItem(int index, Item item){
			items[index] = item;
		}
		void Inventory::printInventory(){
			for(int i = 0; i < _INVENTORYSIZE; i++){
				cout << i << ". " << items[i].getRarity() << " "<< items[i].getName() << endl;
			}
		}
		void Inventory::removeItem(int index){
			items[index] = allItems["Empty"];
		}

		void 	Inventory::removeItem(Item item){
			for(int i = 0; i < _INVENTORYSIZE; i++){
				if(items[i] == item){
					removeItem(i);
				}
			}
		}

		bool Inventory::isEmpty(int index){
			if(items[index] == allItems["Empty"]){
				return true;
			}
			return false;
		}

		bool Inventory::contains(Item item){
			for(int i = 0; i < _INVENTORYSIZE; i++){
				if(items[i] == item){
					return true;
				}
			}
			return false;
		}

