/********************
Dylan Lucero - CSC240
*********************/

#include "point.h"
#include <iostream>

int main() {
    // Creating Point objects
    Point p1; // Default constructor
    Point p2(3, 4); // Overloaded constructor
    Point p3(1234); // Conversion constructor

// Testing the Constructors
    std::cout << "--------------------------------------\n" << "           Dylan Lucero\n" << "--------------------------------------\n" 
              << "Testing Point class constructors:" << '\n' << std::endl;
    std::cout << " Point 1: " << p1 << std::endl;    // Test default constructor
    std::cout << " Point 2: " << p2 << std::endl;    // Test overloaded constructor
    std::cout << " Point 3: " << p3 << std::endl;          // Test conversion constructor
  
// ----------------------------------------------------------------------------------------------------------------------------------------

    std::cout << '\n' << "--------------------------------------" << '\n' << "Testing setCoordinates():\n"  <<  std::endl;
    
    std::cout << " Point 1 before setCoordinates: " << p1 << std::endl;
    p1.setCoordinates(-1, -2);    // Testing on p1
    std::cout << " Point 1 after setCoordinates: " << p1 << std::endl;
    p1.setCoordinates(5000, 9000);
    std::cout << " Point 1 after setCoordinates again: " << p1 << '\n' << std::endl;

    std::cout << " Point 2 before setCoordinates: " << p2 << std::endl;
    p2.setCoordinates(-10, -20);
    std::cout << " Point 2 after setCoordinates: " << p2 << std::endl;
    p2.setCoordinates(1000, 5000);
    std::cout << " Point 2 after setCoordinates again: " << p2 << '\n' << '\n' << "--------------------------------------" << std::endl;
    
    // Reverting back to default
    p2.setCoordinates(3, 4); 
    p1.setCoordinates(0, 0); 
// ----------------------------------------------------------------------------------------------------------------------------------------

    // Testing calcDistance
    std::cout << "Tesing calcDistance(): \n\n " << p1 << " distance from origin: " << p1.calcDistance() << std::endl;
    p1.setCoordinates(5, 5);
    std::cout << " " << p1 << " distance from origin: " << p1.calcDistance() << std::endl;
    std::cout << " " << p2 <<" distance from origin: " << p2.calcDistance() << '\n' << '\n' << "--------------------------------------" << std::endl;
    p1.setCoordinates(0,0);
// ----------------------------------------------------------------------------------------------------------------------------------------

    // Testing quadrant
    std::cout << "Testing quadrant():"<< '\n' <<std::endl;
    std::cout << " Quadrant for " << p1 << ": " << p1.quadrant() << std::endl;
    p1.setCoordinates(-3, -4);
    std::cout << " Quadrant for " << p1 << ": " << p1.quadrant() << std::endl;
    p1.setCoordinates(3,4);
    std::cout << " Quadrant for " << p1 << ": " << p1.quadrant() << std::endl;
    p1.setCoordinates(3,-4);
    std::cout << " Quadrant for " << p1 << ": " << p1.quadrant() << std::endl;
    p1.setCoordinates(0,4);
    std::cout << " Quadrant for " << p1 << ": " << p1.quadrant() << std::endl;
    p1.setCoordinates(3,0);
    std::cout << " Quadrant for " << p1 << ": " << p1.quadrant() << std::endl;
    p1.setCoordinates(-3,4);
    std::cout << " Quadrant for " << p1 << ": " << p1.quadrant() << '\n' << "\n--------------------------------------" << std::endl;
    
    // Reverting back to default
    p1.setCoordinates(0,0); 
// ----------------------------------------------------------------------------------------------------------------------------------------
    std::cout << "Testing Overloaded Operators:\n" << std::endl;
    // Testing operator overloading
    std::cout << " (>):\n";
    std::cout << std::boolalpha << "  Is " << p2 << " further than " << p1 << " from the origin: " << (p2 > p1) << std::endl;
    p2.setCoordinates(0,0);
    p1.setCoordinates(3,4);
    std::cout << std::boolalpha << "  Is " << p2 << " further than " << p1 << " from the origin: " << (p2 > p1) << std::endl;

    std::cout << "\n (Testing against doubles):" << std::endl;
    std::cout << "  Is " << p2 << " further from origin than 5.0: " << (p2 > 5.0) << std::endl;
    p2.setCoordinates(3,4);
    std::cout << "  Is " << p2 << " further from origin than 1.0: " << (p2 > 1.0) << std::endl;


    // Overload the greater than operator (>) as a friend function to determine if a double value is greater than the distance the object is from the origin
    std::cout << "\n  Is 7.0 further from the origin than "<< p2 << ": " << (7.0 > p2) << std::endl;
    std::cout << "  Is -7.0 further from the origin than "<< p2 << ": " << (-7.0 > p2) << std::endl;
    std::cout << "  Is 0.0 further from the origin than "<< p2 << ": " << (0.0 > p2) << std::endl;

    // Overloaded (-) operator as a member function to calculate the distance between two points
    std::cout << "\n(-):\n  Distance between "<< p1 << " and " << p2 << ": " << (p1 - p2).calcDistance() << std::endl;
    p2.setCoordinates(100, 100);
    p1.setCoordinates(1000, 1000);
    std::cout << "  Distance between "<< p1 << " and " << p2 << ": " << (p1 - p2).calcDistance() << std::endl;
    p2.setCoordinates(0,0);
    p1.setCoordinates(1,1);
    std::cout << "  Distance between "<< p1 << " and " << p2 << ": " << (p1 - p2).calcDistance() << "\n\n" << "--------------------------------------" << std::endl;


    

    return 0;
}