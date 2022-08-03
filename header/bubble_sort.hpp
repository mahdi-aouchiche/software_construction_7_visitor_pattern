#ifndef __BUBBLE_SORT_HPP__
#define __BUBBLE_SORT_HPP__

#include "sort.hpp"
#include "container.hpp"

class BubbleSort : public Sort {
     
     public:
	/* Constructors */
    BubbleSort(): Sort() { }

    /* Pure Virtual Functions */
    void sort(Container* container) {
		// set flag to true to start first pass
		bool flag = true;    
    	int numLength = container -> size(); 
    	
		for(int i = 1; (i <= numLength) && flag; i++){
    		flag = false;
    		
			for (int j=0; j < (numLength -1); j++){
				// descending order simply changes to >
    			if (container->at(j+1)->evaluate() < container->at(j)->evaluate()) {    
    				container->swap(j,j+1);

					// indicates that a swap occurred.
       				flag = true;               
    			}
			}
    	} 
	} 
};
#endif //__BUBBLE_SORT_HPP__
