#include "../header/container.hpp"
// Implementation of the set sort function to set the type of sorting algorithm
// set the type of sorting algorithm

void Container::set_sort_function(Sort* sort_function) { 
	this->sort_function = sort_function;
}
