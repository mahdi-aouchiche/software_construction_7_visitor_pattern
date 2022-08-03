#include "../header/iterator.hpp"
#include <iostream>
        
class CountVisitor;
PreorderIterator::PreorderIterator(Base* ptr) : Iterator(ptr) { 
    this->iterators = std::stack<Iterator*>();
}

void PreorderIterator::first() {
    while(!this->iterators.empty()) {
        this->iterators.pop();
    }
    if(this->self_ptr) {
        Iterator* root_itr = this->self_ptr->create_iterator();
        root_itr->first();
        this->iterators.push(root_itr);
        
    }
}

void PreorderIterator::next() {
    // The notes say to create an iterator for the item on the top of the stack, but the stack is
    // an iterator so it should probably say create an item for the current of the iterator on the
    // top of the stack
    Iterator* top_itr = this->iterators.top()->current()->create_iterator();
    top_itr->first();
    this->iterators.push(top_itr);
    while(!this->iterators.empty() && this->iterators.top()->is_done()) {
        this->iterators.pop();
        if(!this->iterators.empty()) {
            this->iterators.top()->next();
        }
    }
}

bool PreorderIterator::is_done() {
    return this->iterators.empty();
}

Base* PreorderIterator::current() {
    if(!this->iterators.empty()) {
    	this->iterators.top()->current()->accept(visitor);
        return this->iterators.top()->current();
    }
    return nullptr;
}
