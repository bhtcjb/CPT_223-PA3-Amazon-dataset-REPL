// Blake Turman
#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include "LinkedList.hpp"

#include <cstddef>
#include <functional>

template <typename Key, typename Value>
class HashTable {

    public:

    using BucketIterator = typename LinkedList<Key, Value>::Iterator;

    // Constructor
    HashTable() : capacity(8), size(0) {

        table = new LinkedList<Key, Value>[capacity];
    }

    // Destructor
    ~HashTable() {

        delete[] table;
    }

    // Copy Constructor
    HashTable(const HashTable& other) : capacity(other.capacity), size(other.size) {

        table = new LinkedList<Key, Value>[capacity];

        for (size_t i = 0; i < capacity; ++i) {

            table[i] = other.table[i];
        }

    }

    // Copy Assignment
    HashTable& operator=(const HashTable& other) {

        if (this != &other) {

            HashTable copy(other);
            std::swap(table, copy.table);
            std::swap(capacity, copy.capacity);
            std::swap(size, copy.size);
        }

        return *this;
    }

    // Move Constructor
    HashTable(HashTable&& other) noexcept : table(other.table), capacity(other.capacity), size(other.size) {

        other.table = nullptr;
        other.size = other.capacity = 0;
    }

    // Move Assignment
    HashTable& operator=(HashTable&& other) noexcept {

        if (this != &other) {

            std::swap(table, other.table);
            std::swap(capacity, other.capacity);
            std::swap(size, other.size);
        }

        return *this;
    }

    // Inserts new key value pair to table
    // Returns true if successful
    // Post-cond: Rehashing occurs if the size/capacity ratio will excede 0.75 upon insertion
    bool insert(const Key& key, const Value& value) {

        bool success = true;

        // if adding this increases the load factor to more than 0.75
        if (((float)(size + 1) / capacity) > 0.75) {

            // resize and rehash
            success = rehash();
        }

        if (success) {

            // generate hashed index
            size_t index = std::hash<Key>{}(key) % capacity;

            // insert and increase element count
            success = table[index].insert(key, value);

            if (success) {

                ++size;
            }

        }
        
        return success;

    }

    // Returns iterator at position of first element of bucket with specified key or past the end iterator if not found
    BucketIterator find(const Key& key) const {

        return table[std::hash<Key>{}(key) % capacity].find(key);
    }

    // Removes first element with specified key from table
    // Returns true if successful
    bool remove(const Key& key) {

        // generate hased index
        size_t index = std::hash<Key>{}(key) % capacity;

        // remove at index and decrease element count
        bool success = table[index].remove(key);

        if (success) {

            --size;
        }

        return success;
    }

    // Getters
    const size_t& getSize() const {

        return size;
    }

    const size_t& getCapacity() const {

        return capacity;
    }


    private:

    LinkedList<Key, Value>* table; // dynamic array of linked lists
    size_t capacity;
    size_t size;

    // Doubles capacity and rehashes all values to new size
    // Returns true if successful
    bool rehash() {
        
        size_t newCapacity = capacity * 2;
        bool success = true;
        LinkedList<Key, Value>* newTable = new(std::nothrow) LinkedList<Key, Value>[newCapacity];

        // check failed allocation
        if (newTable == nullptr) {
            
            success = false;
        }

        // for each index in the array
        for (size_t i = 0; i < capacity && success; ++i) {

            // iterate through the linked list
            for (BucketIterator j = table[i].start(); !j.atEnd() && success; ++j) {

                // rehash every new value to the new array
                success = newTable[std::hash<Key>{}(j.getKey()) % newCapacity].insert(j.getKey(), j.getData());
            }
        }

        // check for successfully rehashing
        if (success) {
            
            // set table to the new rehased table
            delete[] table;
            table = newTable;
            capacity = newCapacity;
        }
        else {
            
            delete[] newTable;
        }
    
        return success;
    }
    
};

#endif