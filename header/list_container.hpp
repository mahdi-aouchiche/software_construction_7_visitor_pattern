#ifndef __LIST_CONTAINER_HPP__
#define __LIST_CONTAINER_HPP__

#include "base.hpp"
#include <iostream>
#include "sort.hpp"
#include <list>
using namespace std;

class SelectionSort;
class BubbleSort;

class ListContainer : public Container {
	private:
	//Sort* sortFunction;
	list<Base *> items;
		
	public:
	ListContainer() {};
	ListContainer(Sort* function) {
	  sort_function = function;
	};
		
	void add_element(Base* element){
		items.push_back(element);
	};
	
	Base* at(int i) {
		int k = 0;
	     	if ( i < items.size())
			for(list<Base *>::iterator it = items.begin(); it != items.end(); ++it){
		     		if ( i  == k ) return *it;
				k++;
			}
		return NULL;
	};
	
	int size() {
		return items.size();
	};
    
	void sort() {
		if (sort_function)
		{
           	sort_function->sort(this);
			return;
		} else {
			cout << "Error no sort function defined";
			return;
		}
	}
	
	void set_sort_function(Sort* function) {
		sort_function = function;
	}
	
	void print(){
		for(list <Base* >::iterator it = items.begin(); it != items.end(); ++it){
			cout <<(*it) -> stringify() << "\n";
		}
	};
	
	void swap (int i, int j){
		Base* temp_var ;
		Base* temp_var2 ;
		int k;
		k = 0;
	
		for(list<Base *>::iterator it = items.begin(); it != items.end(); ++it) {
		    if ( i  == k ) {
			temp_var = *it;
			break;
		     }
		    k++; 
		}
		k = 0;
		for(list<Base *>::iterator it = items.begin(); it != items.end(); ++it) {
            if ( j  == k ) {
               	temp_var2 = *it;
				*it = temp_var;
               	break;
			}
		
			k++;
        }
		
		k = 0;
		for(list<Base *>::iterator it = items.begin(); it != items.end(); ++it) {
            if ( i  == k ) {
               	*it = temp_var2;
               	break;
            }
			k++;
        }
	}
};

#endif //__LISTCONTAINER_HPP__

