#ifndef __ABS_HPP__
#define __ABS_HPP__

#include <string>
#include "math.h"
#include "base.hpp"
#include "decorator.hpp"
#include "iterator.hpp"
#include "visitor.hpp"
using namespace std;

class Abs : public Decorator{
  	private: 
	Base* left;  
  	
	public:   
	/* Constructors */
  	Abs(Base *orig): Decorator(orig) {
		left = orig;
	};

	/* Virtual functions */
	double evaluate(){ 
		return abs(Temp_base->evaluate());
	}

	string stringify() {
		return " |" + Temp_base->stringify() + "| ";
	}
	
	virtual Base* get_left() { 
		return left;
	}
  	
	virtual Base* get_right() { 
		return nullptr;
	}

	virtual Iterator* create_iterator(){
      	UnaryIterator* it = new UnaryIterator(this);
      	return it;
	}
	
	void accept(CountVisitor* v){
		v->visit_abs();		
	}
};

#endif //__PAREN_HPP__
