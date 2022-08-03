#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

class Rand : public Base 
{
    private:    
    // create a local var initialized to zero
    double ouput = 0; 

    public:
    Rand() : Base() {
        // saved value into local var
        ouput = rand() % 100; 
    } 
    
    double evaluate() { 
        // return the local var
        return ouput; 
    } 

    string stringify() { 
        // convert output to string
        return to_string(ouput); 
    } 

    Base* get_left() { 
        return nullptr; 
    }
	
    Base* get_right() { 
        return nullptr; 
    }
	 
    Iterator* create_iterator() { 
        return new NullIterator(this); 
    }
	
    void accept(CountVisitor* v) { 
        v->visit_rand(); 
    }
};

#endif //__RAND_HPP__
