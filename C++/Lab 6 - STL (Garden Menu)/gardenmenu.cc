#include <iostream>
#include <vector>
#include <algorithm>
#include "garden.h"

using namespace std;

std::vector<Plant*> plants;

// A couple of parameters for sort() function
bool compareByName(Plant* a, Plant* b) { return a->getName() < b->getName(); }
bool compareByCost(Plant* a, Plant* b) { return a->getCost() < b->getCost(); }

int main() {
    
    string name, color;
    bool isAnnual;
    char annualChoice, type;
    int choice;
    double cost;

    while (true) {
        cout << "-------------------\n|   Garden Menu   |\n| by Dylan Lucero |\n-------------------\n";


        cout << "1. Add Plant\n2. Remove Plant\n3. Display\n4. Total Cost\n5. Sort by Name\n6. Sort by Cost\n7. Quit\n";
        cin >> choice;  

        // Check if cin took the correct type, prevents infinite loop
        if (cin.fail()){
            cout << "Type Error - integers only\n" << "Exiting" << endl;
            return 0;
        }
        
        // Switch statement for menu
        switch (choice) {
            
            // Add Plant Case
            case 1: {
                
                cout << "Enter plant type (P - Plant   F - Flower): ";
                cin >> type;

                // Check that only F and P are accepted
                if(type != 'F' && type != 'f' && type != 'P' && type != 'p'){
                    cout << "Invalid plant type.\n";
                    break;
                }

                // Flower 
                if(type == 'F' || type == 'f'){

                    cout << "Enter the flower name: ";
                    cin.ignore();
                    getline(cin, name); // getline() instead of cin to account for spaces e.g. African Daisy

                    cout << "Enter the flower cost: $";
                    cin >> cost;
                    cout << "Enter the flower color: ";
                    cin >> color;
                    cout << "Is the flower annual (Y/N)?: ";
                    cin >> annualChoice;

                    if(annualChoice == 'Y' || annualChoice == 'y'){ isAnnual = true; } 
                    else { isAnnual = false; }

                    // Adding new Flower object(with parameters) to plants vector
                    plants.push_back(new Flower(name, cost, color, isAnnual));
                    break;

                    // Plant
                }else if(type == 'P'|| type== 'p'){

                    cout << "Enter the plant name: ";
                    cin.ignore();
                    getline(cin, name); // Accounting for spaces here as well

                    cout << "Enter the plant cost: $";
                    cin >> cost;
                    plants.push_back(new Plant(name, cost));
                    break;
                    }
                }
                
            // Remove Plant Case
            case 2: {
                string name;
                cout << "Enter plant name: ";
                cin >> name;

                //Check if plants is empty
                if(plants.size() == 0){
                    cout << "No plants to remove\n";
                    break;
                }
                //Checking if plant exists in plants
                for (auto it = plants.begin(); it != plants.end(); ++it) {
                    if (**it == name) {
                        plants.erase(it);
                        break;
                    } else {
                        cout << "ERROR - Plant does not exist in garden.\n";
                        break;
                    }
                }
            }

            // Display Plants Case
            case 3: {
                int n=1; //Counter for plant number
    
                for (auto it = plants.begin(); it != plants.end(); ++it) {
                    cout << "Plant "<< n << ": ";
                    n++;
                    cout << **it << "\n";
                }
                break;
            }

            // Total Cost Case
            case 4: {
                double totalCost = 0;
                for (auto it = plants.begin(); it != plants.end(); ++it) {
                    totalCost += (*it)->getCost();
                }
                cout << "Total cost of all plants: " << totalCost << "\n";
                break;
            }

            // Sorting by Name Case
            case 5: {
                sort(plants.begin(), plants.end(), compareByName);
                break;
            }

            // Sorting by Cost Case
            case 6: {
                sort(plants.begin(), plants.end(), compareByCost);
                break;
            }
            
            // Exit
            case 7: {
                return 0;
            }

            default:{
                cout << "Invalid Input" << endl;
                break;
            }
        }
    }
    return 0;
}
