// g++-11 -std=c++17 test/TestHashTable.cpp -Iinclude -o testexe && ./testexe
#include "HashTable.hpp"

#include <cassert>
#include <iostream>

void testBasic() {

    std::cerr << "Test 1: Basic - Initialization, Insertion" << std::endl;

    HashTable<int, char> table = HashTable<int, char>{};

    // test default initialization
    assert(table.getSize() == 0);
    assert(table.getCapacity() == 8);

    // test insertion
    assert(table.insert(1, 'a'));
    assert(table.getSize() == 1);
    assert(table.getCapacity() == 8);

    std::cerr << "PASSED" << std::endl;
}

void testInsert() {

    std::cerr << "Test 2: Insert()" << std::endl;

    HashTable<int, char> table = HashTable<int, char>{};

    // test chained insertion
    assert(table.insert(1, 'a'));
    assert(table.getSize() == 1);
    assert(table.getCapacity() == 8);
    assert(table.insert(2, 'b'));
    assert(table.getSize() == 2);
    assert(table.insert(3, 'c'));
    assert(table.getSize() == 3);
    assert(table.insert(4, 'd'));
    assert(table.getSize() == 4);
    assert(table.insert(2, 'e'));
    assert(table.getSize() == 5);
    assert(table.getCapacity() == 8);
    assert(table.insert(5, 'f'));
    assert(table.getSize() == 6);
    assert(table.getCapacity() == 8);

    // test rehash
    assert(table.insert(6, 'g'));
    assert(table.getSize() == 7);
    assert(table.getCapacity() == 16);

    // test post-rehash insertion
    assert(table.insert(5, 'h'));
    assert(table.getSize() == 8);
    assert(table.getCapacity() == 16);

    std::cerr << "PASSED" << std::endl;
}

void testFind() {

    std::cerr << "Test 3: Find()" << std::endl;

    HashTable<int, char> table = HashTable<int, char>{};

    // populate table
    assert(table.insert(1, 'a'));
    assert(table.insert(2, 'b'));
    assert(table.insert(3, 'c'));
    assert(table.insert(2, 'd'));
    assert(table.insert(2, 'e'));
    assert(table.insert(5, 'f'));
    assert(table.getSize() == 6);
    assert(table.getCapacity() == 8);

    // test fail key not found
    assert(table.find(0).atEnd());

    // test find single value buckets
    assert(*(table.find(1)) == 'a');
    assert(*(table.find(3)) == 'c');
    assert(*(table.find(5)) == 'f');

    // test iterate through bucket
    HashTable<int, char>::BucketIterator iterator = table.find(2);
    assert(iterator++.getData() == 'e');
    assert(iterator++.getData() == 'd');
    assert(iterator++.getData() == 'b');
    assert(iterator.atEnd());

    // trigger rehash
    assert(table.insert(7, 'g'));
    assert(table.getSize() == 7);
    assert(table.getCapacity() == 16);

    // test find single value buckets
    assert(*(table.find(1)) == 'a');
    assert(*(table.find(3)) == 'c');
    assert(*(table.find(5)) == 'f');
    assert(*(table.find(7)) == 'g');

    // test iterate through bucket
    iterator = table.find(2);
    assert(iterator++.getData() == 'b');
    assert(iterator++.getData() == 'd');
    assert(iterator++.getData() == 'e');
    assert(iterator.atEnd());


    std::cerr << "PASSED" << std::endl;
}

void testRemove() {

    std::cerr << "Test 4: Remove()" << std::endl;

    HashTable<int, char> table = HashTable<int, char>{};

    // populate table
    assert(table.insert(1, 'a'));
    assert(table.insert(2, 'b'));
    assert(table.insert(3, 'c'));
    assert(table.insert(2, 'd'));
    assert(table.insert(2, 'e'));
    assert(table.insert(5, 'f'));
    assert(table.getSize() == 6);
    assert(table.getCapacity() == 8);

    // test fail key not found
    assert(table.remove(0) == false);
    assert(table.getSize() == 6);

    // test remove single value buckets
    assert(table.remove(1) == true);
    assert(table.getSize() == 5);
    assert(table.remove(1) == false);
    assert(table.remove(3) == true);
    assert(table.getSize() == 4);
    assert(table.remove(3) == false);
    assert(table.remove(5) == true);
    assert(table.getSize() == 3);
    assert(table.remove(5) == false);

    // test remove through bucket
    assert(table.remove(2) == true);
    assert(table.getSize() == 2);
    assert(table.remove(2) == true);
    assert(table.getSize() == 1);
    assert(table.remove(2) == true);
    assert(table.getSize() == 0);
    assert(table.remove(2) == false);
    assert(table.getSize() == 0);

    // populate table and trigger rehash
    assert(table.insert(1, 'a'));
    assert(table.insert(2, 'b'));
    assert(table.insert(3, 'c'));
    assert(table.insert(2, 'd'));
    assert(table.insert(2, 'e'));
    assert(table.insert(5, 'f'));
    assert(table.getSize() == 6);
    assert(table.getCapacity() == 8);
    assert(table.insert(7, 'g'));
    assert(table.getSize() == 7);
    assert(table.getCapacity() == 16);

    // test remove single value buckets
    assert(table.remove(1) == true);
    assert(table.getSize() == 6);
    assert(table.remove(1) == false);
    assert(table.remove(3) == true);
    assert(table.getSize() == 5);
    assert(table.remove(3) == false);
    assert(table.remove(5) == true);
    assert(table.getSize() == 4);
    assert(table.remove(5) == false);
    assert(table.remove(7) == true);
    assert(table.getSize() == 3);

    // test remove through bucket
    assert(table.remove(2) == true);
    assert(table.getSize() == 2);
    assert(table.remove(2) == true);
    assert(table.getSize() == 1);
    assert(table.remove(2) == true);
    assert(table.getSize() == 0);
    assert(table.remove(2) == false);
    assert(table.getSize() == 0);

    std::cerr << "PASSED" << std::endl;
}

int main() {

    testBasic();
    testInsert();
    testFind();
    testRemove();

}