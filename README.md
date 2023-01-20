# Software Construction: Visitor Pattern

> Author: Mahdi Aouchiche (<https://github.com/mahdi-aouchiche/software_construction_7_visitor_pattern>)

## Iterator Class

You've been provided with four files which contain declrations and definitions for the following five iterator classes:

* `Iterator`: this is the base class for defining the interface for all the other iterator classes
* `NullIterator`: this iterator is created by expression tree classes which have no children to iterator over such as the operands
* `BinaryIterator`: this iterator is created by expression tree classes with two children, such as operators, and returns one of the children per iteration
* `UnaryIterator`: this iterator is created by expression tree classes with one child, such as decorators, and returns the only child on its first iteration
* `PreorderIterator`: this iterator is created by a user to traverse an entire expression tree. Note that it will skip the first node in the expression tree so its helpful to add a "dummy" decorator node as root which will be skipped

These classes are declared in the file `iterator.hpp` but defined in other files with the exception of the `Iterator` and `NullIterator` classes, which are both declared and defined in `iterator.hpp`. The first step of this lab is to modify your existing expression tree classes to work with these iterators. You will need to perform the following steps to integrate these iterator classes with your expression tree objects to allow your tree to be iterated:

* Add a pure virtual `Iterator* create_iterator()` function to your `Base` class
* Declare and define an appropriate `Iterator* create_iterator()` function for each of your `Base` subclasses
* Add pure virtual `Base* get_left()` and `Base* get_right()` functions to your `Base` class
* Declare and define `get_left()` and `get_right()` functions for each of your `Base` subclasses (some of these will necessarily return `nullptr`)
* Make sure that each class is returning the correct type of iterator (Null, Binary, or Unary) and that the iterator is initialized (using its constructor) for that object before its returned

Before moving on to the visitor portion of this lab, make sure to create a number of unit tests to make sure you are correctly iterating over every node in various expression trees. If you do not test your iteratior before attempting to use it with your visitor you will likely get difficult to debug results or segmentation faults.

## The Visitor Class

Now Create a visitor pattern which, when paired with the `PreorderIterator` class from the previous section will be used to count the number of each type of element within an expression. To do this, create a single `CountVisitor` class which can be paired with a `PreorderIterator` to visit each node in an expression tree and count them. The below code is truncated, and the full code has been provided in visitor.hpp.

```c++
class CountVisitor {
    private:
        // Composite Pattern Tracking Members
        int ops;
        int rands;
        ...
        int sub;
        int pow;
       
        // Decorator Pattern Tracking Members
        int ceil;
        int floor;
        ...
        int trunc;
        int paren;

    public:
        CountVisitor();

        // Composite Pattern Visit Functions
        void visit_op();
        int op_count();
        void visit_rand();
        int rand_count();
        ...
        void visit_sub();
        int sub_count();
        void visit_pow();
        int pow_count();

        // Decorator Pattern Visit Functions
        void visit_ceil();
        int ceil_count();
        void visit_floor();
        int floor_count();
        ...
        void visit_trunc();
        int trunc_count();
        void visit_paren();
        int paren_count();
};
```

There is one function for visiting each type of node in the expression tree, and another for retrieving the count of the node types that have been visited.

## Modifying the Expression Tree Elements

In addition to completing the functionality for the above visitor class, modify all the classes that can exist in an expression tree to allow for the `CountVisitor` to access them. Add the function `void accept(CountVisitor*)` to the necessary classes which will then call the appropriate function within the `CountVisitor`.

Once you have implemented this function and created the `CountVisitor` class you will need to create a number of unit tests to verify that your visitor paired with your iterator can correctly count all the nodes in various expression trees. Remember that the preorder iterator will skip the root node, so you should add a "dummy" decorator to your tree and make sure to account for this in your unit tests.

### To run the project nicely use the following commands

```c++
cmake -S . -B build
cmake --build build/
```

### 2 executables are created, use one of the commands to run an executable

```c++
// visitor pattern
./build/visitor_tests
./build/visitor_pattern
```
