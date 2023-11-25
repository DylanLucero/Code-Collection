#include <iostream>
#include <string>
#include "garden.h"

using namespace std;

// Plant Class
Plant :: Plant(string plantName, double plantCost){
    name = plantName;
    cost = plantCost;
}

// Getters
string Plant :: getName(){ return name; }
double Plant :: getCost(){ return cost; }

// Setters
bool Plant :: operator == (string pName){ return (name == pName); }

// Display Formatting
void Plant :: display(ostream& out){ out << name << "  $" << cost; }

ostream& operator << (ostream& out, Plant& plant){
    plant.display(out);
    return out;
}


// Flower Class
Flower :: Flower(string plantName, double plantCost, string flowerColor, bool flowerType) : Plant(plantName, plantCost){
    color = flowerColor;
    isAnnual = flowerType;
}
// Getters
string Flower :: getColor(){ return color; }

void Flower :: display(ostream& out){
    Plant :: display(out);
    out << "  " << color;
    if(isAnnual){
        out << "  Annual";
    } else{
        out << "  Perennial";
    }
}

ostream& operator << (ostream& out, Flower& f){
    f.display(out);
    return out;
}
