#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"
#include <string>
#include <iostream>
#include "iterator.hpp"
#include "visitor.hpp"
using namespace std; 

class Add : public Base {
    private:
    Base* intr_1;
    Base* intr_2;

    public:  
	/* Constructor */      
	Add(Base* a, Base* b) : intr_1(a), intr_2(b) {}
        
	/* Virtual functions */
	double evaluate() { 
		return intr_1->evaluate() + intr_2->evaluate();
	}
        
	string stringify() { 
		return intr_1->stringify() +" + " + intr_2->stringify();
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
		v->visit_add();
	}
};

#endif //__ADD_HPP__
