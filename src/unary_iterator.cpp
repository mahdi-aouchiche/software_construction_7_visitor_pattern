#include "../header/iterator.hpp"

UnaryIterator::UnaryIterator(Base* ptr) : Iterator(ptr) {
    this->c = ChildIndicator::left;
}

void UnaryIterator::first() { 
    this->c = ChildIndicator::left; 
}

void UnaryIterator::next() {
    if(this->c == ChildIndicator::left) {
        this->c = ChildIndicator::end;
    }
    this->c = ChildIndicator::end;
}

bool UnaryIterator::is_done() { 
    if(this->c == ChildIndicator::end) {
        return true;
    }
    return false;
}

Base* UnaryIterator::current() { 
    if(this->c == ChildIndicator::left) {
        return this->self_ptr->get_left();
    }
    return nullptr;
}
