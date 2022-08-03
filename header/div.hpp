#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include <string>
#include <iostream>
#include "iterator.hpp"
#include "visitor.hpp"
using namespace std;

class Div : public Base {
    private:
    Base* intr_1;
    Base* intr_2;

    public:
    /* Constructor */
    Div(Base* a, Base* b) : intr_1(a), intr_2(b) {}

    /* functions */    
	double evaluate() { 
        return intr_1->evaluate() / intr_2->evaluate();
    }
        
	string stringify() { 
        return intr_1->stringify() + " / " + intr_2->stringify();
    }
        
	Base* get_left() { 
        return intr_1;
    };
	
	Base* get_right() { 
        return intr_2;
    };
	
	Iterator* create_iterator() { 
        return new BinaryIterator(this);
    };
	
	void accept(CountVisitor* v) { 
        v->visit_div();
    }
};

#endif // __DIV_HPP__
