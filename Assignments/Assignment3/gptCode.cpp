#include <iostream>

// Define a simple class
class MyClass {
public:
    // Constructor
    MyClass(int value) : data(value) {
        std::cout << "Constructor called with value: " << value << std::endl;
    }

    // Destructor
    ~MyClass() {
        std::cout << "Destructor called. Object with value " << data << " is being destroyed." << std::endl;
    }

    // Member function
    void displayData() {
        std::cout << "Data: " << data << std::endl;
    }

private:
    int data;
};

int main() {
    // Creating an instance on the stack
    MyClass objectOnStack(42);
    objectOnStack.displayData(); // Accessing member function

    // Creating an instance on the heap using new
    MyClass *objectOnHeap = new MyClass(99);
    objectOnHeap->displayData(); // Accessing member function

    // Don't forget to delete the heap-allocated object to avoid memory leaks
    delete objectOnHeap;

    return 0;
}
