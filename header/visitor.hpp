#ifndef __COUNT_VISITOR_HPP__
#define __COUNT_VISITOR_HPP__

class CountVisitor{
    private:
    int ops = 0;
    int rands = 0;
    int mults = 0 ;
    int divs = 0 ;
    int add = 0 ;
    int sub = 0 ;
    int pow = 0;
        
    int ceil = 0 ;
    int floor = 0 ;
    int abs = 0;
    int trunc = 0;
    int paren = 0;

    public:
	/*Constructor*/
    CountVisitor() {};

    void visit_op() 	{ ++ops;	} 
    int op_count() 		{ return ops; 	}
    void visit_rand()	{ ++rands;	}
    int rand_count() 	{ return rands; }	
    void visit_mult()	{ ++mults;	}
    int mult_count() 	{ return mults; }
    void visit_div() 	{ ++divs;	}
    int div_count() 	{ return divs; 	}
    void visit_add() 	{ ++add;	}
    int add_count() 	{ return add; 	}
    void visit_sub() 	{ ++sub;	}
    int sub_count() 	{ return sub ; 	}
    void visit_pow() 	{ ++pow;	}
    int pow_count() 	{ return pow; 	}

    void visit_ceil()	{ ++ceil;	}
    int ceil_count() 	{ return ceil; 	}
    void visit_floor()	{ ++floor;	}
    int floor_count() 	{ return floor;	}
    void visit_abs()	{ ++abs;	}
    int abs_count()		{ return abs;	} 
    void visit_trunc()	{ ++trunc;	}
    int trunc_count() 	{ return trunc; }
    void visit_paren()	{ ++paren;	}
    int paren_count() 	{ return paren; }
};

#endif //__COUNT_VISITOR_HPP__
