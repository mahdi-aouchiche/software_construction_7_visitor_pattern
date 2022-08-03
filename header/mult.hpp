#ifndef __Mult_HPP__
#define __Mult_HPP__

#include "base.hpp"
#include <string>
#include <iostream>
#include "iterator.hpp"
#include "visitor.hpp" 
using namespace std;

class Mult : public Base {
    private:
 	Base* intr_1;
    Base* intr_2;
    
    public:
    Mult(Base* a, Base* b) : intr_1(a), intr_2(b) {}
    double evaluate() { 
        return intr_1->evaluate() * intr_2->evaluate();
    }
    
    string stringify() { 
        return intr_1->stringify() +" * " + intr_2->stringify(); 
    }

    Base* get_left() { 
        return intr_1; 
    }

	Base* get_right() { 
        return intr_2; 
    }

	Iterator* create_iterator() { 
        return new BinaryIterator(this); 
    }

	void accept(CountVisitor* v) { 
        v->visit_mult(); 
    }
};

#endif //__ADD_HPP__

