#include <iostream>
#include <string>

using namespace std;

class Plant{
    private:
        string name;
        double cost;
    public:
        //Setter
        Plant(string plantName, double plantCost);
        // Getters
        string getName();
        double getCost();
        // Overloaded Operators
        bool operator == (string pName);        
        virtual void display(ostream& out);
        friend ostream& operator << (ostream& out, Plant& plant);
};

class Flower : public Plant{
    private:
        string color;
        bool isAnnual;
    public:
        Flower(string plantName, double plantCost, string flowerColor, bool flowerType);
        string getColor();
        virtual void display(ostream& out);
        friend ostream& operator << (ostream& out, Flower& f);
};

