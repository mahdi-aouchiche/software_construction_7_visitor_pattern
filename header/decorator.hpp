#ifndef __DECORATOR_HPP__
#define __DECORATOR_HPP__

#include "base.hpp"
#include <string>
using namespace std;

class Decorator : public Base {
    protected:
    Base *Temp_base;

    public:
    /* Constructors */
    Decorator(Base *orig) {
		Temp_base = orig;       
	};

	/* Virtual functions*/
	double evaluate(){
		return Temp_base -> evaluate();
	}

	string stringify(){
		return Temp_base -> stringify(); 	
	};	
};

#endif //__DECORATOR_HPP__
