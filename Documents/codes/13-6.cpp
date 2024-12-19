#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Shape
class Shape {
protected:
    string color;
    bool filled;

public:
    Shape(string color, bool filled) : color(color), filled(filled) {}

    string getColor() const {
        return color;
    }

    void setColor(string color) {
        this->color = color;
    }

    bool isFilled() const {
        return filled;
    }

    void setFilled(bool filled) {
        this->filled = filled;
    }

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;

    virtual void display() const {
        cout << "Shape [color=" << color << ", filled=" << (filled ? "true" : "false") << "]";
    }
};

// Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(string color, bool filled, double radius) : Shape(color, filled), radius(radius) {}

    double getRadius() const {
        return radius;
    }

    void setRadius(double radius) {
        this->radius = radius;
    }

    double getArea() const override {
        return M_PI * radius * radius;
    }

    double getPerimeter() const override {
        return 2 * M_PI * radius;
    }

    void display() const override {
        cout << "Circle [radius=" << radius << "]";
        Shape::display();
        cout << ", area=" << getArea() << ", perimeter=" << getPerimeter() << "]" << endl;
    }
};

// Square
class Square : public Shape {
private:
    double side;

public:
    Square(string color, bool filled, double side) : Shape(color, filled), side(side) {}

    double getSide() const {
        return side;
    }

    void setSide(double side) {
        this->side = side;
    }

    double getArea() const override {
        return side * side;
    }

    double getPerimeter() const override {
        return 4 * side;
    }

    void display() const override {
        cout << "Square [side=" << side << "]";
        Shape::display();
        cout << ", area=" << getArea() << ", perimeter=" << getPerimeter() << "]" << endl;
    }
};

// Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(string color, bool filled, double width, double height) 
        : Shape(color, filled), width(width), height(height) {}

    double getWidth() const {
        return width;
    }

    void setWidth(double width) {
        this->width = width;
    }

    double getHeight() const {
        return height;
    }

    void setHeight(double height) {
        this->height = height;
    }

    double getArea() const override {
        return width * height;
    }

    double getPerimeter() const override {
        return 2 * (width + height);
    }

    void display() const override {
        cout << "Rectangle [width=" << width << ", height=" << height << "]";
        Shape::display();
        cout << ", area=" << getArea() << ", perimeter=" << getPerimeter() << "]" << endl;
    }
};

int main() {
    Circle circle("Red", true, 5.0);
    Square square("Blue", false, 4.0);
    Rectangle rectangle("Green", true, 3.0, 6.0);

    cout << "Circle details:" << endl;
    circle.display();

    cout << "\nSquare details:" << endl;
    square.display();

    cout << "\nRectangle details:" << endl;
    rectangle.display();

    return 0;
}
