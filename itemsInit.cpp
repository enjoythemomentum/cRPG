#include "classItem.h"
#include "items.h"

std::unordered_map<std::string, Item> allItems = {
    {"Empty", {"Empty", "An empty slot", 0, 0, 0, 0, ""}},
    {"Fist", {"Fist", "A fist that punches", 1, 1, 0, 0, ""}},
    {"Fire Sword",
     {"Fire Sword", "A sword that is on fire", 15, 5, 3, 3, "Legendary"}},
    {"Bow", {"Bow", "A bow that shoots arrows", 6, 0, 5, 2, "Common"}},
    {"Arrow",
     {"Arrow", "An arrow that is shot from a bow", 3, 0, 0, 0, "Common"}},
    {"Health Potion",
     {"Health Potion", "A potion that heals you", 0, 0, 0, 0, "Common"}},
    {"Mana Potion",
     {"Mana Potion", "A potion that restores mana", 0, 0, 0, 0, "Common"}},
    {"Sword", {"Sword", "A sword that is sharp", 10, 3, 0, 0, "Common"}},
    {"Axe", {"Axe", "An axe that is heavy", 12, 4, 0, 0, "Common"}},
    {"Dagger", {"Dagger", "A dagger that is small", 8, 2, 0, 0, "Common"}},
    {"Staff", {"Staff", "A staff that is magical", 5, 0, 8, 4, "Common"}},
    {"Wand", {"Wand", "A wand that is magical", 4, 0, 10, 5, "Common"}},
    {"Helmet",
     {"Helmet", "A helmet that protects your head", 0, 0, 0, 0, "Common"}},
    {"Chestplate",
     {"Chestplate", "A chestplate that protects your chest", 0, 0, 0, 0,
      "Common"}},
    {"Leggings",
     {"Leggings", "Leggings that protect your legs", 0, 0, 0, 0, "Common"}},
    {"Boots", {"Boots", "Boots that protect your feet", 0, 0, 0, 0, "Common"}},
    {"Ring", {"Ring", "A ring that is magical", 0, 0, 0, 0, "Common"}},
    {"Amulet", {"Amulet", "An amulet that is magical", 0, 0, 0, 0, "Common"}},
    {"Gloves",
     {"Gloves", "Gloves that protect your hands", 0, 0, 0, 0, "Common"}},
    {"Shield", {"Shield", "A shield that protects you", 0, 0, 0, 0, "Common"}}};
