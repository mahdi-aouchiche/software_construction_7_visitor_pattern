#ifndef __SELECTION_SORT_HPP__
#define __SELECTION_SORT_HPP__

#include "sort.hpp"
#include "container.hpp"

class SelectionSort : public Sort 
{
    public:
	/* Constructors */
    SelectionSort(): Sort() { }

    /* Pure Virtual Functions */
  	void sort(Container* container) {
		int i, j, min; 
		for(i = 0; i < container->size()- 1 ; ++i ) {
			min = i;
			for(j = i + 1; j < container->size(); ++j) {
				if(container->at(j)->evaluate() < container->at(min)->evaluate()) {
					min = j;	
				} 
			} 
			
			if(min != i) { 
				container->swap(i,min);
			}
		}	
	} 
};

#endif //__SELECTION_SORT_HPP__
