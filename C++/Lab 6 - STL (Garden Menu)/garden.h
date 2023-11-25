#include <iostream>
#include <string>

using namespace std;

class Plant{
    private:
        string name;
        double cost;
    public:
        Plant(string plantName, double plantCost);

        string getName();
        double getCost();
        bool operator == (string pName);   

        friend ostream& operator << (ostream& out, Plant& plant);
        virtual void display(ostream& out);

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

