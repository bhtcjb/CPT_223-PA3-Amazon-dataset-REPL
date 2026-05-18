// Blake Turman
#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <new>
#include <utility>

template <typename Key, typename Value>
class LinkedList {

    class Node;

    public:

    // Constructor
    LinkedList() : head(nullptr) {
    }

    // Destructor
    ~LinkedList() {

        destroyList();
    }

    // Copy Constructor
    LinkedList(const LinkedList& other) : head(nullptr) {

        Node* original = other.head,
            * copy = nullptr;

        if (original != nullptr) {

            head = new Node(original->key, original->data);
            copy = head;
            original = original->getNext();

            while (original != nullptr) {

                copy->setNext(new Node(original->key, original->data));

                copy = copy->getNext();
                original = original->getNext();
            }
        }
    }

    // Copy Assignment
    LinkedList& operator=(const LinkedList& other) {

        if (this != &other) {

            LinkedList copy(other);
            std::swap(head, copy.head);
        }

        return *this;
    }

    // Move Constructor
    LinkedList(LinkedList&& other) noexcept : head(other.head) {

        other.head = nullptr;
    }

    // Move Assignment
    LinkedList& operator=(LinkedList&& other) noexcept {

        if (this != &other) {

            std::swap(head, other.head);
        }

        return *this;
    }

    class Iterator {

        public:

        // Default Constructor
        Iterator(Node* curr) : current(curr) {
        }

        // Constructor with find logic
        Iterator(const Key& key, Node* curr) : current(curr) {

            bool found = false;
            
            // move current iterator position until key is found
            while (!found && current != nullptr) {

                if (current->getKey() == key) {

                    found = true;
                }
                else {

                    current = current->getNext();
                }
            }

        }

        // Destructor
        ~Iterator() {
        }

        // Copy Constructor
        Iterator(const Iterator& other) {
            current = other.current;
        }

        // Copy Assignment
        Iterator& operator=(const Iterator& other) {

            if (this != &other) {

                current = other.current;
            }

            return *this;
        }

        // Move Constructor
        Iterator(Iterator&& other) noexcept {

            current = other.current;
            other.current = nullptr;
        }

        // Move Assignment
        Iterator& operator=(Iterator&& other) noexcept {

            if (this != &other) {

                current = other.current;
                other.current = nullptr;
            }

            return *this;            
        }

        // Prefix Increment
        Iterator& operator++() {

            if (current != nullptr) {

                current = current->getNext();
            }

            return *this;
        }

        // Postfix Increment
        Iterator operator++(int) {

            Iterator temp = *this;

            if (current != nullptr) {

                current = current->getNext();
            }

            return temp;

        }

        // Returns true if iterated past the last element
        bool atEnd() const {

            return current == nullptr;
        }

        // Getters
        const Key& getKey() const {

            return current->getKey();
        }

        const Value& getData() const {

            return current->getData();
        }

        const Value& operator*() const {

            return current->getData();
        }

        private:

        LinkedList<Key, Value>::Node* current;

        friend class LinkedList;

    };

    // Inserts new node at front of list
    // Returns true if successful
    bool insert(const Key& key, const Value& data) {

        Node* newNode = new(std::nothrow) Node(key, data);
        bool success = false;

        if (newNode != nullptr) {

            newNode->setNext(head);
            head = newNode;

            success = true;
        }

        return success;
    }

    // Inserts new node after specified iterator position
    // Returns true if successful
    // Note: since this function inserts after the specified position, attempting to insert with atEnd() iterator position will fail
    bool insert(const Key& key, const Value& data, Iterator& position) {

        bool success = false;

        if (!position.atEnd()) {

            Node* curr = position.current,
                *newNode = new(std::nothrow) Node(key, data);

            if (newNode != nullptr) {

                newNode->setNext(curr->getNext());
                curr->setNext(newNode);

                success = true;
            }

        }


        return success;
    }

    // Returns iterator at first position of node with value or past the end iterator if not found
    Iterator find(const Key& key) const {

        return Iterator(key, head);
    }

    // Returns iterator at first element of list
    Iterator start() const {

        return Iterator(head);
    }

    // Removes node from front of list
    // Returns true if successful
    bool remove() {

        bool success = false;

        if (!empty()) {

            Node* temp = head;

            head = head->getNext();

            delete temp;
            temp = nullptr;

            success = true;
        }

        return success;
    }

    // Removes first node with specified key
    // Returns true if successful
    bool remove(const Key& key) {

        bool success = false;
        Node* curr = head,
            *prev = nullptr;

        // Iterate until specified node is reached
        for (; curr != nullptr && curr->getKey() != key; prev = curr, curr = curr->getNext());

        // if found
        if (curr != nullptr) {

            // if at head
            if (prev == nullptr) {

                head = curr->getNext();
            }
            else {
                
                prev->setNext(curr->getNext());
            }

            success = true;

            delete curr;
            curr = nullptr;
        }

        return success;

    }

    // Returns true if list is empty
    bool empty() const {

        return head == nullptr;
    }

    private:

    Node* head;

    class Node {

        public:

        // Constructor
        Node(const Key& key, const Value& data) : key(key), data(data), next(nullptr) {
        }

        // Destructor
        ~Node() {
        }

        // Copy Constructor
        Node(const Node& other) : key(other.key), data(other.data) {
        }

        // Copy Assignment
        Node& operator=(const Node& other) {
            if (this != &other) {
                key = other.key;
                data = other.data;
            }

            return *this;
        }

        // Move Constructor
        Node(Node&& other) noexcept : key(std::move(other.key)), data(std::move(other.data)), next(other.next) {

            other.next = nullptr;
        }

        // Move Assignment
        Node& operator=(Node&& other) noexcept {

            if (this != &other) {
                data = std::move(other.data);
                key = std::move(other.key);

                next = other.next;

                other.next = nullptr;
            }

            return *this;
        }

        // Setters
        void setNext(Node* next) {
            this->next = next;
        }

        // Getters
        Node* getNext() const {
            return next;
        }

        const Key& getKey() const {
            return key;
        }

        const Value& getData() const {
            return data;
        }

        private:

        Key key;
        Value data;
        Node* next;

        friend class LinkedList;

    };


    // Destroys entire list
    void destroyList() {

        Node* curr = head,
            *temp = nullptr;
        
        while (curr != nullptr) {

            temp = curr;
            curr = curr->getNext();

            delete temp;
            temp = nullptr;
        }

    }

};

#endif