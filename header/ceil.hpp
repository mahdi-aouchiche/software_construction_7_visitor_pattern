#ifndef __CEIL_HPP__
#define __CEIL_HPP__

#include "base.hpp"
#include "decorator.hpp"
#include <string>
#include "math.h"
#include "iterator.hpp"
#include "visitor.hpp"
using namespace std;

class Ceil : public Decorator{
    private: 
	Base* left;

    public:
    /* Constructors */
    Ceil(Base *orig): Decorator(orig) { 
		left = orig; 
	};
        
	/* functions */
	double evaluate() { 
		return ceil(Temp_base -> evaluate());
	}
	
	virtual Base* get_left() { 
		return left;
	}
  
	virtual Base* get_right() { 
		return nullptr;
	}
	
    virtual Iterator* create_iterator() {
		UnaryIterator* it = new UnaryIterator(this);
		return it;
	}
	
	void accept(CountVisitor* v) { 
		v->visit_ceil();
	}
};

#endif //__CEIL_HPP__

