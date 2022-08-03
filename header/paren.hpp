#ifndef __PAREN_HPP__
#define __PAREN_HPP__

#include "base.hpp"
#include "decorator.hpp"
#include <string>
#include "iterator.hpp"
#include "visitor.hpp"

using namespace std;

class Paren : public Decorator
{
    private:
	Base* left;

    public:
    /* Constructors */
    Paren(Base *orig): Decorator(orig) { 
        left = orig; 
    };

    /* Functions */
	string stringify() { 
        return "(" + Temp_base ->  stringify() +")"; 
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
        v->visit_paren(); 
    }
};

#endif //__PAREN_HPP__
