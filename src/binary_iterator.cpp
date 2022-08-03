#include "../header/iterator.hpp"

BinaryIterator::BinaryIterator(Base* ptr) : Iterator(ptr) {
    this->c = ChildIndicator::left;
}

void BinaryIterator::first() {
    this->c = ChildIndicator::left;
}

void BinaryIterator::next() {
    if(this->c == ChildIndicator::left) {
        this->c = ChildIndicator::right;
    }
    else if(this->c == ChildIndicator::right) {
        this->c = ChildIndicator::end;
    } 
    else {
        this->c = ChildIndicator::end;
    }
}

bool BinaryIterator::is_done() {
    if(this->c == ChildIndicator::end) {
        return true;
    }
    return false;
}

Base* BinaryIterator::current() {
    if(this->c == ChildIndicator::left) {
        return this->self_ptr->get_left();
    }
    else if(this->c == ChildIndicator::right) {
        return this->self_ptr->get_right();
    }
    return nullptr;
}
