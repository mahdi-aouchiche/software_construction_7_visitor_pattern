#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <string>
#include "iterator.hpp"
#include "visitor.hpp"

class Op : public Base 
{
    // create a local var initialized to zero
	double ouput = 0; 

    public:
    Op(double value) : Base() {
        // saved value into local var
        ouput = value; 
    } 
        
    double evaluate() { 
        // return the local var
        return ouput; 
    } 
    
    string stringify() { 
        // convert output to string
        return std::to_string(ouput); 
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
        v->visit_op(); 
    } 
};

#endif //__OP_HPP__
