#include "../header/op.hpp"
#include "../header/add.hpp"
#include "../header/iterator.hpp"
#include <iostream>
#include "../header/sub.hpp"
#include "../header/mult.hpp"
#include "../header/div.hpp"
#include "../header/pow.hpp"
#include "../header/rand.hpp"
#include "../header/ceil.hpp"
#include "../header/floor.hpp"
#include "../header/abs.hpp"
#include "../header/trunc.hpp"
#include "../header/paren.hpp"
using namespace std;

int main(int argv, char** argc) {

    Op* _nine = new Op(-9);
    Op* nine = new Op(9);
    Op* three = new Op(3);
    Op* zero = new Op(0);

    // 9 + 3 = 12
    Add* first = new Add(nine,three);

    // 12 * (-9) = -108
    Mult* second = new Mult(first,_nine);

    // -108 + 0 = -108
    Add* third = new Add(second,zero);

    // |9 + 3 * -9 + 0| = |-108| = 108
    Abs* test_p = new Abs(third);

    Paren* dummy_p = new Paren(test_p);
    Iterator* a = new PreorderIterator(dummy_p);
    
    a -> first();
    while (!a->is_done()){
        cout << a->current()->stringify() << " = " << a->current()->evaluate() <<  endl;
        a->next();
    }
}
