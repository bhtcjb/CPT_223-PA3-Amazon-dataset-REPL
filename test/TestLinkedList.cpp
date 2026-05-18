// g++-11 -std=c++17 test/TestLinkedList.cpp -Iinclude -o testexe && ./testexe
#include "LinkedList.hpp"

#include <cassert>
#include <iostream>

void testBasic() {

    std::cerr << "Test 1: Basic - Initialization, Insertion, Iteration" << std::endl;

    LinkedList<int, char> list = LinkedList<int, char>{};
    LinkedList<int, char>::Iterator iterator = list.start();

    // test default initialization
    assert(list.empty());
    assert(iterator.atEnd());

    // test insert
    assert(list.insert(1, 'a'));
    assert(!list.empty());

    // test iterator at right position
    iterator = list.start();
    assert(!iterator.atEnd());
    assert(iterator.getKey() == 1);
    assert(iterator.getData() == 'a');
    assert((++iterator).atEnd());

    // test second insert for correct linking
    assert(list.insert(2, 'b'));
    assert(!list.empty());

    // test iterate to end
    iterator = list.start();
    assert(!iterator.atEnd());
    assert(iterator.getKey() == 2);
    assert(iterator.getData() == 'b');
    assert(!(++iterator).atEnd());
    assert(iterator.getKey() == 1);
    assert(*iterator == 'a');
    assert((++iterator).atEnd());

    std::cerr << "PASSED" << std::endl;
}

void testInsert() {

    std::cerr << "Test 2: Insert()" << std::endl;

    LinkedList<int, char> list = LinkedList<int, char>{};
    LinkedList<int, char>::Iterator iterator = list.start();

    // test failed insert at end
    assert(!list.insert(1, 'a', iterator));
    assert(list.empty());

    // test chained inserts
    assert(list.insert(1, 'a'));
    assert(list.insert(2, 'b'));
    assert(list.insert(3, 'c'));
    assert(!list.empty());
    iterator = list.start();
    assert(iterator++.getData() == 'c');
    assert(iterator++.getData() == 'b');
    assert(iterator++.getData() == 'a');
    assert(iterator.atEnd());

    // test insert middle
    iterator = list.start();
    ++iterator;
    assert(list.insert(4, 'd', iterator));
    assert(iterator++.getData() == 'b');
    assert(iterator++.getData() == 'd');
    assert(iterator++.getData() == 'a');
    assert(iterator.atEnd());

    // test insert end
    iterator = list.start();
    ++iterator;
    ++iterator;
    ++iterator;
    assert(list.insert(5, 'e', iterator));
    assert(iterator++.getData() == 'a');
    assert(iterator++.getData() == 'e');
    assert(iterator.atEnd());

    std::cerr << "PASSED" << std::endl;
}

void testRemove() {

    std::cerr << "Test 3: Remove()" << std::endl;

    LinkedList<int, char> list = LinkedList<int, char>{};
    LinkedList<int, char>::Iterator iterator = list.start();

    // check failed remove from empty
    assert(!list.remove());

    // populate list
    assert(list.insert(1, 'a'));
    assert(list.insert(2, 'b'));
    assert(list.insert(3, 'c'));

    // basic remove til empty
    assert(list.remove());
    iterator = list.start();
    assert(iterator.getData() == 'b');
    assert(list.remove());
    iterator = list.start();
    assert(iterator.getData() == 'a');
    assert(list.remove());
    assert(list.empty());
    iterator = list.start();
    assert(iterator.atEnd());

    // populate list
    assert(list.insert(1, 'a'));
    assert(list.insert(2, 'b'));
    assert(list.insert(3, 'c'));
    assert(list.insert(4, 'd'));

    // remove front
    assert(list.remove(4));
    iterator = list.start();
    assert(iterator.getData() == 'c');

    // remove middle
    assert(list.remove(2));
    assert(iterator.getData() == 'c');
    iterator++;
    assert(iterator.getData() == 'a');

    // remove end
    assert(list.remove(1));
    iterator = list.start();
    assert(iterator++.getData() == 'c');
    assert(iterator.atEnd());

    // fail key not found
    assert(!list.remove(0));
    assert(!list.empty());

    // remove with key til empty
    assert(list.remove(3));
    assert(list.empty());

    std::cerr << "PASSED" << std::endl;
}

void testFind() {

    std::cerr << "Test 4: Find()" << std::endl;

    LinkedList<int, char> list = LinkedList<int, char>{};

    // populate list
    assert(list.insert(1, 'a'));
    assert(list.insert(2, 'b'));
    assert(list.insert(3, 'c'));
    assert(list.insert(2, 'd'));
    assert(list.insert(5, 'e'));

    // fail key not found
    assert((list.find(0)).atEnd());

    // find front key
    assert(*(list.find(5)) == 'e');

    // find middle key
    assert(*(list.find(3)) == 'c');

    // find end key
    assert(*(list.find(1)) == 'a');

    // find first of duplicates
    assert(*(list.find(2)) == 'd');

    // find second of duplicates
    assert(list.remove(2));
    assert(*(list.find(2)) == 'b');   

    std::cerr << "PASSED" << std::endl;
}

int main() {

    testBasic();
    testInsert();
    testRemove();
    testFind();

}