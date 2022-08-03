#ifndef __TEST_ITERATOR_HPP__
#define __TEST_ITERATOR_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "add.hpp"
#include "iterator.hpp"
#include <iostream>
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "ceil.hpp"
#include "floor.hpp"
#include "abs.hpp"
#include "trunc.hpp"
#include "paren.hpp"
using namespace std;

TEST(Basic_unit_Test, Paren) {
    Op* half = new Op(.5);
    Op* nine = new Op(9);
    Op* one = new Op(1);
    Op* two = new Op(2);
    Add* left = new Add(half, nine);
    Sub* right = new Sub(two, one);
    Mult* tree = new Mult(left, right);

    Paren* decorator_test = new Paren(tree);
    Iterator* it = decorator_test->create_iterator();

    EXPECT_EQ(decorator_test->evaluate(), 9.5);
    EXPECT_EQ(it->current()->evaluate(), 9.5);
}

TEST(Basic_unit_Test, Trunc) {
    Op* half = new Op(.5);
    Op* nine = new Op(9);
    Op* one = new Op(1);
    Op* two = new Op(2);
    Add* left = new Add(half, nine);
    Sub* right = new Sub(two, one);
    Mult* tree = new Mult(left, right);

    Trunc* decorator_test = new Trunc(tree);
    Iterator* it = decorator_test->create_iterator();

    EXPECT_EQ(decorator_test->evaluate(), 9.5);
    EXPECT_EQ(it->current()->evaluate(), 9.5);
}

TEST(Basic_unit_Test, Abs) {
    Op* half = new Op(.5);
    Op* nine = new Op(9);
    Op* one = new Op(1);
    Op* two = new Op(2);
    Add* left = new Add(half, nine);
    Sub* right = new Sub(two, one);
    Mult* tree = new Mult(left, right);

    Abs* decorator_test = new Abs(tree);
    Iterator* it = decorator_test->create_iterator();

    EXPECT_EQ(decorator_test->evaluate(), 9.5);
    EXPECT_EQ(it->current()->evaluate(), 9.5);
}

TEST(Basic_unit_Test, Floor) {
    Op* half = new Op(.5);
    Op* nine = new Op(9);
    Op* one = new Op(1);
    Op* two = new Op(2);
    Add* left = new Add(half, nine);
    Sub* right = new Sub(two, one);
    Mult* tree = new Mult(left, right);

    Floor* decorator_test = new Floor(tree);
    Iterator* it = decorator_test->create_iterator();

    EXPECT_EQ(decorator_test->evaluate(), 9);
    EXPECT_EQ(it->current()->evaluate(), 9.5);
}

TEST(Basic_unit_Test, Ceil) {
    Op* half = new Op(.5);
    Op* nine = new Op(9);
    Op* one = new Op(1);
    Op* two = new Op(2);
    Add* left = new Add(half, nine);
    Sub* right = new Sub(two, one);
    Mult* tree = new Mult(left, right);

    Ceil* decorator_test = new Ceil(tree);
    Iterator* it = decorator_test->create_iterator();
    
    EXPECT_EQ(decorator_test->evaluate(), 10);
    EXPECT_EQ(it->current()->evaluate(), 9.5); 
}

TEST(Basic_unit_Test, Add) {
    Op* _nine = new Op(-9);
    Op* nine = new Op(9);
    Add* additionTest = new Add(_nine, nine);
    Add* test_ite = new Add(additionTest, nine);
    Iterator* a = test_ite -> create_iterator();
    EXPECT_EQ(test_ite->evaluate(), 9);
    EXPECT_EQ(a->current()->evaluate(), 0);
    a->first();
    EXPECT_EQ(a->current()->evaluate(), 0);
    a->next();
    EXPECT_EQ(a->current()->evaluate(), 9);

}

TEST(Basic_unit_Test, Sub) {
    Op* _nine = new Op(-9);
    Op* nine = new Op(9);
    Add* additionTest = new Add(_nine, _nine);
    Sub* test_ite = new Sub(additionTest, nine);
    Iterator* a = test_ite -> create_iterator();
    EXPECT_EQ(test_ite->evaluate(), -27);
    EXPECT_EQ(a->current()->evaluate(), -18);
    a->next();
    EXPECT_EQ(a->current()->evaluate(), 9);
    a->first();
    EXPECT_EQ(a->current()->evaluate(), -18);
}

TEST(Basic_unit_Test, Mult) {
    Op* _eight = new Op(-8);
    Op* nine = new Op(9);
    Add* additionTest = new Add(_eight, nine);
    Mult* test_ite = new Mult(additionTest, nine);
    Iterator* a = test_ite -> create_iterator();
    EXPECT_EQ(test_ite->evaluate(), 9);
    EXPECT_EQ(a->current()->evaluate(), 1);
    a ->first();
    EXPECT_EQ(a->current()->evaluate(), 1);
    a -> next();
    EXPECT_EQ(a->current()->evaluate(), 9);
}

TEST(Basic_unit_Test, Div) {
    Op* _nine = new Op(-9);
    Op* nine = new Op(9);
    Add* additionTest = new Add(_nine, nine);
    Div* test_ite = new Div(additionTest, nine);
    Iterator* a = test_ite -> create_iterator();
    EXPECT_EQ(test_ite->evaluate(), 0);
    EXPECT_EQ(a->current()->evaluate(), 0);
    a ->first();
    EXPECT_EQ(a->current()->evaluate(), 0);
    a -> next();
    EXPECT_EQ(a->current()->evaluate(), 9);
}

TEST(Basic_unit_Test, Op) {
    Op* nine = new Op(9);
    Iterator* a = nine -> create_iterator();
    EXPECT_EQ(nine->evaluate(), 9);
    EXPECT_EQ(a->current(), nullptr);
    a->first();
    EXPECT_EQ(a->current(), nullptr);
    a->next();
    EXPECT_EQ(a->current(), nullptr);
}

TEST(Basic_unit_Test, Rand) {
    Rand* new_ran = new Rand();
    Iterator* a = new_ran -> create_iterator();
    EXPECT_EQ(a->current(), nullptr);
    a->first();
    EXPECT_EQ(a->current(), nullptr);
    a-> next();
    EXPECT_EQ(a->current(), nullptr);
}

TEST(Basic_preorder_Test, PreOrder) {
    Op* _nine = new Op(-9);
    Op* nine = new Op(9);
    Op* three = new Op(3);
    Op* zero = new Op(0);
    Add* first = new Add(nine,three);
    Mult* second = new Mult(first,_nine);
    Add* third = new Add(second,zero);   
    Paren* test_p = new Paren(third);
    Paren* dummy_p = new Paren(test_p);
    Iterator* a = new PreorderIterator(dummy_p);
    
    a->first();
    EXPECT_EQ(a->current()->evaluate(), -108);
    a->next();
    EXPECT_EQ(a->current()->evaluate(), -108);
    a->next();
    EXPECT_EQ(a->current()->evaluate(), -108);
    a->next();
    EXPECT_EQ(a->current()->evaluate(), 12);
    a->next();
    EXPECT_EQ(a->current()->evaluate(), 9);  
    a->next();
    EXPECT_EQ(a->current()->evaluate(), 3); 
    a->next();
    EXPECT_EQ(a->current()->evaluate(), -9);  
    a->next();
    EXPECT_EQ(a->current()->evaluate(), 0);
    a->next();
    EXPECT_EQ(a->current(),nullptr );  
    EXPECT_EQ(a->visitor->add_count(), 2);
    EXPECT_EQ(a->visitor->paren_count(), 1);
    EXPECT_EQ(a->visitor->mult_count(), 1);  
}

TEST(All_Tests, combination_test) {
    Op* _nine = new Op(-9);
	Op* _five = new Op(-5);    
	Op* _one  = new Op(-1);
    Op* zero  = new Op(0);
	Op* one   = new Op(1);
    Op* three = new Op(3);
	Op* four  = new Op(4);
	Op* seven = new Op(7);	
	Op* nine  = new Op(9);
	Op* ten   = new Op(10);

	Add* add  = new Add(seven,three);
    Sub* sub  = new Sub(ten, nine);
	Add* br1   = new Add(add, sub);
	Trunc* tru = new Trunc(br1);	

	Mult* mult = new Mult( zero,_nine);
    Div* div   = new Div(ten , _one);
	Abs* abs   = new Abs(div);	

	Sub* br2   = new Sub(mult, abs);
	Paren* par  = new Paren(br2);
	
	Add* add2  = new Add(tru, par);
	Floor* flr = new Floor(add2);

	Pow* pow   = new Pow(three, four); 
    Div* head  = new Div(pow, flr);

    Ceil* dummy_p = new Ceil(head);
    
    Iterator* a = new PreorderIterator(dummy_p);
    a -> first();
    while (!a->is_done()){
		a->current();
		a->next();
    }
    EXPECT_EQ(a->current(),nullptr );
    EXPECT_EQ(a->visitor->add_count(), 3);
    EXPECT_EQ(a->visitor->sub_count(), 2);
	EXPECT_EQ(a->visitor->trunc_count(), 1);
	EXPECT_EQ(a->visitor->mult_count(), 1);
	EXPECT_EQ(a->visitor->div_count(), 2);
	EXPECT_EQ(a->visitor->abs_count(), 1);
    EXPECT_EQ(a->visitor->paren_count(), 1);
	EXPECT_EQ(a->visitor->floor_count(), 1);
	EXPECT_EQ(a->visitor->pow_count(), 1);
	EXPECT_EQ(a->visitor->ceil_count(), 0);
    EXPECT_EQ(a->visitor->mult_count(), 1);
}

#endif //__TEST_ITERATOR_HPP__
