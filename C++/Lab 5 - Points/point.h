/********************
Dylan Lucero - CSC240
*********************/

#include <iostream>

class Point {
private:
    double x, y;

public:
    // Constructors
    Point();
    Point(double xVal, double yVal);
    Point(int value);
    // Member functions
    void setCoordinates(double xVal, double yVal);
    double calcDistance() const;
    int quadrant() const;

    // Overloaded operators
    bool operator>(const Point& other) const;
    bool operator>(double value) const;

    Point operator-(const Point& other) const;

    // Friend functions
    friend bool operator>(double value, const Point& point);
    friend std::ostream& operator<<(std::ostream& os, const Point& point);


};