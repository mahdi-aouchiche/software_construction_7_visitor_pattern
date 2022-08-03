#ifndef __FLOOR_HPP__
#define __FLOOR_HPP__

#include "base.hpp"
#include "decorator.hpp"
#include <string>
#include "math.h"
#include "iterator"
#include "visitor.hpp"
using namespace std;

class Floor : public Decorator{
    private:
    Base* left;

	public:
    /* Constructors */
    Floor(Base *orig): Decorator(orig) {
		left = orig;
	};

	/* Functions */
	double evaluate() { 
		return floor(Temp_base -> evaluate());
	}
	
	Base* get_left() { 
		return left;
	}
  
    Base* get_right() { 
		return nullptr;
	}
  
  	Iterator* create_iterator() {
        UnaryIterator* it = new UnaryIterator(this);
        return it;
  	}

	void accept(CountVisitor* v) { 
		v->visit_floor(); 
	}
};

#endif //__FLOOR_HPP__
