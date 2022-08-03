#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

#include <stack>
#include "base.hpp"
#include "container.hpp"
#include "visitor.hpp"

class Base;
class CountVisitor;

enum ChildIndicator { left, right, end };

class Iterator {
    protected:
    Base* self_ptr;
        
    public:
    CountVisitor* visitor;
	
    Iterator(Base* ptr) { 
        this->self_ptr = ptr; 
        this -> visitor = new   CountVisitor();
    }

    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool is_done() = 0;
    virtual Base* current() = 0;
};

class BinaryIterator : public Iterator {
    protected:
    ChildIndicator c;

    public:
    BinaryIterator(Base* ptr);

    void first();
    void next();
    bool is_done();
    Base* current();
};

class UnaryIterator : public Iterator {
    protected:
    ChildIndicator c;

    public:
    UnaryIterator(Base* ptr);

    void first();
    void next();
    bool is_done();
    Base* current();
};

class NullIterator : public Iterator {
    public:
    NullIterator(Base* ptr) : Iterator(ptr) {}

    void first() {}
    
    void next() {}
    
    bool is_done() {
        return true;
    }

    Base* current() { 
        return nullptr; 
    }
};

class PreorderIterator : public Iterator {
    protected:
    std::stack<Iterator*> iterators;

    public:
    PreorderIterator(Base* ptr);

    void first();
    void next();
    bool is_done();
    Base* current();
};

#endif  //__ITERATOR_HPP__
