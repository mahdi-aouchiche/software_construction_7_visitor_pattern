#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include "math.h"
#include "iterator.hpp"
#include "visitor.hpp" 

using namespace std;

class Pow : public Base 
{	
	private:
	Base* intr_1;
	Base* intr_2;	
    
	public:
    Pow(Base* a, Base* b) : intr_1(a), intr_2(b){ }
	
	double evaluate() { 
		return pow(intr_1->evaluate(), intr_2->evaluate()); 
	}
	
	string stringify() { 
		return intr_1->stringify() +" ** " + intr_2->stringify(); 
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
		v->visit_pow(); 
	}
};

#endif //__POW_HPP__
                    
