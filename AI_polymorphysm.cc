#include <iostream>
#include <vector>

// Base class
class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
};

// Derived class 1
class Circle : public Shape {
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.14159 * radius * radius;
    }
private:
    double radius;
};

// Derived class 2
class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
private:
    double width;
    double height;
};

// Function that uses polymorphism
void print_areas(const std::vector<Shape*>& shapes) {
    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->area() << std::endl;
    }
}

int main() {
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    
    print_areas(shapes);
    
    // Clean up
    for (auto& shape : shapes) {
        delete shape;
    }
    
    return 0;
}