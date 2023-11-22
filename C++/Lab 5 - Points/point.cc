/********************
Dylan Lucero - CSC240
*********************/

#include "point.h"
#include <cmath>

Point::Point() : x(0), y(0) {}

Point::Point(double xVal, double yVal) : x(xVal), y(yVal) {}

Point::Point(int value) {
    // Initialize x and y from a 4-digit integer (yyxx)
    x = value % 100;
    y = value / 100;
    if (value < 1000) {
        y = 0;
    }
}

void Point::setCoordinates(double xVal, double yVal) {
    x = xVal;
    y = yVal;
}

double Point::calcDistance() const {
    return sqrt(x * x + y * y);
}

int Point::quadrant() const {
    if (x == 0 && y == 0) {
        return 0; // Origin
    } else if (x == 0) {
        return 6; // Y-axis
    } else if (y == 0) {
        return 5; // X-axis
    } else if (x > 0 && y < 0){
        return 4;
    } else if(y > 0 && x < 0){
        return 2;
    } else if(x < 0 && y < 0){
        return 3;
    } else{
        return 1;
    }
}

bool Point::operator>(const Point& other) const {
    return calcDistance() > other.calcDistance();
}

bool Point::operator>(double value) const {
    if((calcDistance() > value )== 1){
        return true;
    } else{
        return false;
    }
}

bool operator>(double value, const Point& point) {
    return value > point.calcDistance();
}

Point Point::operator-(const Point& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return Point(dx, dy);
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x << "," << point.y << ")";
    return os;
}