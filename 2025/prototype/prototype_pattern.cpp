#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>

using namespace std;

// Abstract Prototype Class
class Shape {
protected:
    string type;
    int x;
    int y;
    string color;

public:
    Shape() : x(0), y(0), color("white") {}
    
    // Copy constructor - key for prototype pattern
    Shape(const Shape& source) {
        this->type = source.type;
        this->x = source.x;
        this->y = source.y;
        this->color = source.color;
        cout << "Copying shape using copy constructor: " << type << endl;
    }

    virtual ~Shape() {}

    // Pure virtual clone method - the heart of Prototype pattern
    virtual Shape* clone() const = 0;

    virtual void draw() const {
        cout << "Drawing " << type << " at (" << x << ", " << y << ") with color " << color << endl;
    }

    void setPosition(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void setColor(const string& color) {
        this->color = color;
    }

    string getType() const {
        return type;
    }
};

// Concrete Prototype 1: Circle
class Circle : public Shape {
private:
    int radius;

public:
    Circle() : radius(10) {
        type = "Circle";
        cout << "Creating new Circle with default constructor" << endl;
    }

    // Copy constructor
    Circle(const Circle& source) : Shape(source) {
        this->radius = source.radius;
        cout << "Circle copy constructor called" << endl;
    }

    // Parametrized constructor
    Circle(int radius, const string& color) : radius(radius) {
        type = "Circle";
        this->color = color;
        cout << "Creating Circle with parametrized constructor" << endl;
    }

    // Clone method - uses copy constructor
    Circle* clone() const override {
        return new Circle(*this);
    }

    void draw() const override {
        cout << "Drawing " << type << " with radius " << radius 
             << " at (" << x << ", " << y << ") with color " << color << endl;
    }

    void setRadius(int r) {
        radius = r;
    }
};

// Concrete Prototype 2: Rectangle
class Rectangle : public Shape {
private:
    int width;
    int height;

public:
    Rectangle() : width(20), height(10) {
        type = "Rectangle";
        cout << "Creating new Rectangle with default constructor" << endl;
    }

    // Copy constructor
    Rectangle(const Rectangle& source) : Shape(source) {
        this->width = source.width;
        this->height = source.height;
        cout << "Rectangle copy constructor called" << endl;
    }

    // Parametrized constructor
    Rectangle(int width, int height, const string& color) 
        : width(width), height(height) {
        type = "Rectangle";
        this->color = color;
        cout << "Creating Rectangle with parametrized constructor" << endl;
    }

    // Clone method - uses copy constructor
    Rectangle* clone() const override {
        return new Rectangle(*this);
    }

    void draw() const override {
        cout << "Drawing " << type << " with width " << width 
             << " and height " << height 
             << " at (" << x << ", " << y << ") with color " << color << endl;
    }

    void setDimensions(int w, int h) {
        width = w;
        height = h;
    }
};

// Prototype Registry/Manager
class ShapeRegistry {
private:
    unordered_map<string, Shape*> prototypes;

public:
    ShapeRegistry() {
        cout << "\n=== Initializing Shape Registry ===" << endl;
    }

    ~ShapeRegistry() {
        for (auto& pair : prototypes) {
            delete pair.second;
        }
    }

    void addPrototype(const string& key, Shape* prototype) {
        prototypes[key] = prototype;
        cout << "Registered prototype: " << key << endl;
    }

    Shape* createShape(const string& key) {
        auto it = prototypes.find(key);
        if (it != prototypes.end()) {
            cout << "\nCloning " << key << " from registry..." << endl;
            return it->second->clone();
        }
        return nullptr;
    }
};

// Client code
int main() {
    cout << "===== PROTOTYPE PATTERN DEMONSTRATION =====" << endl;
    cout << "\n--- Phase 1: Creating Original Objects ---" << endl;
    
    // Create original objects using constructors
    Circle* blueCircle = new Circle(15, "blue");
    blueCircle->setPosition(10, 20);
    
    Rectangle* redRectangle = new Rectangle(30, 40, "red");
    redRectangle->setPosition(50, 60);

    cout << "\n--- Phase 2: Setting up Prototype Registry ---" << endl;
    ShapeRegistry registry;
    registry.addPrototype("BlueCircle", blueCircle);
    registry.addPrototype("RedRectangle", redRectangle);

    cout << "\n--- Phase 3: Cloning Objects from Registry ---" << endl;
    
    // Clone objects using the prototype pattern
    Shape* clonedCircle1 = registry.createShape("BlueCircle");
    Shape* clonedCircle2 = registry.createShape("BlueCircle");
    Shape* clonedRectangle = registry.createShape("RedRectangle");

    cout << "\n--- Phase 4: Modifying Cloned Objects ---" << endl;
    
    // Modify cloned objects
    if (Circle* c1 = dynamic_cast<Circle*>(clonedCircle1)) {
        c1->setPosition(100, 100);
        c1->setColor("green");
        c1->setRadius(25);
    }

    if (Circle* c2 = dynamic_cast<Circle*>(clonedCircle2)) {
        c2->setPosition(200, 200);
        c2->setColor("yellow");
    }

    if (Rectangle* r = dynamic_cast<Rectangle*>(clonedRectangle)) {
        r->setPosition(150, 150);
        r->setDimensions(50, 50);
    }

    cout << "\n--- Phase 5: Drawing All Shapes ---" << endl;
    cout << "\nOriginal shapes:" << endl;
    blueCircle->draw();
    redRectangle->draw();

    cout << "\nCloned and modified shapes:" << endl;
    clonedCircle1->draw();
    clonedCircle2->draw();
    clonedRectangle->draw();

    cout << "\n--- Phase 6: Direct Cloning (without registry) ---" << endl;
    Circle* directClone = blueCircle->clone();
    directClone->setPosition(300, 300);
    directClone->setColor("purple");
    cout << "\nDirect clone:" << endl;
    directClone->draw();

    // Cleanup
    delete clonedCircle1;
    delete clonedCircle2;
    delete clonedRectangle;
    delete directClone;
    // Note: blueCircle and redRectangle are deleted by the registry destructor

    cout << "\n===== DEMONSTRATION COMPLETE =====" << endl;
    
    return 0;
}
