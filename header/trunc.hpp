#ifndef __TRUNC_HPP__
#define __TRUNC_HPP__

#include "base.hpp"
#include "decorator.hpp"
#include <string>
#include "math.h"
#include "iterator.hpp"
#include "visitor.hpp"
using namespace std;

class Trunc : public Decorator
{
    private:
	double result; 
	Base* left;		

    public:
    /* Constructors */
    Trunc (Base *orig): Decorator(orig) { 
		left = orig;
		result = orig->evaluate();
	};

    /* Functions */
 	string stringify() { 
        return to_string(result);	
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
        v->visit_trunc(); 
    }
};

#endif //__TRUNC_HPP__

