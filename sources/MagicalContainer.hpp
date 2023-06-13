#pragma once
#include <iostream>
#include <stdexcept>

namespace ariel {
    bool isPrime(int num) {
        if(num == 2){
            return true;
        }
        if (num < 2 || (num & 1) == 0) {
            return false;
        }
        for (int i = 3; i * i <= num; i+=2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    class MagicalContainer {
    private:
        // Node structure for the MagicalContainer
        struct Node {
            int value;

            Node* nextInContainer;
            Node* nextInAscendingContainer;
            Node* nextInSidecrossContainer;
            Node* nextInPrimeContainer;

            Node(int val) : value(val), nextInContainer(nullptr), nextInAscendingContainer(nullptr),
                nextInSidecrossContainer(nullptr), nextInPrimeContainer(nullptr) {}
        };

        int containerSize;
        int primeContainerSize;
        Node* head;
        Node* headAscend;
        Node* headSidecross;
        Node* headPrime;

    public:
        // AscendingIterator class for the linked list
        class AscendingIterator {
        private:
            Node* head;
            Node* current;
            int index;

        public:
            AscendingIterator(Node* node) : head(node), current(node), index(0) {}
            // Constructor that takes a MagicalContainer object as an argument
            AscendingIterator(const MagicalContainer& container) : head(container.getHeadAscend()), current(container.getHeadAscend()), index(0) {}

            AscendingIterator& operator=(const AscendingIterator &other) {
                if (this != &other)
                {
                    if (head != other.head && head != nullptr && other.head != nullptr){
                        throw std::runtime_error("Cannot assign iterators from different containers");
                    }

                    head = other.head;
                    index = other.index;
                    current = other.current;
                }

                return *this;
            }

            // Dereference operator
            int& operator*() {
                return current->value;
            }

            // Pre-increment operator
            AscendingIterator& operator++() {
                if (current != nullptr) {
                    current = current->nextInAscendingContainer;
                    index++;
                }
                else{
                    throw std::runtime_error("runtime_error: Iterator out of range");
                }
                return *this;
            }

            // Equality comparison operator
            bool operator==(const AscendingIterator& other) const {
                return current == other.current;
            }

            // Inequality comparison operator
            bool operator!=(const AscendingIterator& other) const {
                return !(*this == other);
            }

            // Greater than comparison operator
            bool operator>(const AscendingIterator& other) const {
                return index > other.index;
            }

            // Less than comparison operator
            bool operator<(const AscendingIterator& other) const {
                return index < other.index;
            }

            // Create an AscendingIterator pointing to the beginning of the linked list
            AscendingIterator begin() const {
                return AscendingIterator(head);
            }

            // Create an AscendingIterator pointing to the end of the linked list
            AscendingIterator end() const {
                return nullptr;
            }
        };

        class SideCrossIterator {
        private:
            Node* head;
            Node* current;
            int index;

        public:
            SideCrossIterator(Node* node) : head(node), current(node), index(0) {}
            // Constructor that takes a MagicalContainer object as an argument
            SideCrossIterator(const MagicalContainer& container) : head(container.getHeadSidecross()), current(container.getHeadSidecross()), index(0) {}

            SideCrossIterator& operator=(const SideCrossIterator &other) {
                if (this != &other)
                {
                    if (head != other.head && head != nullptr && other.head != nullptr) {}
                        throw std::runtime_error("Cannot assign iterators from different containers");

                    head = other.head;
                    index = other.index;
                    current = other.current;
                }

                return *this;
            }

            // Dereference operator
            int& operator*() {
                return current->value;
            }

            // Pre-increment operator
            SideCrossIterator& operator++() {
                if (current != nullptr) {
                    current = current->nextInSidecrossContainer;
                    index++;
                }
                else{
                    throw std::runtime_error("runtime_error: Iterator out of range");
                }
                return *this;
            }

            // Equality comparison operator
            bool operator==(const SideCrossIterator& other) const {
                return current == other.current;
            }

            // Inequality comparison operator
            bool operator!=(const SideCrossIterator& other) const {
                return !(*this == other);
            }

            // Greater than comparison operator
            bool operator>(const SideCrossIterator& other) const {
                return index > other.index;
            }

            // Less than comparison operator
            bool operator<(const SideCrossIterator& other) const {
                return index < other.index;
            }

            // Create an SideCrossIterator pointing to the beginning of the linked list
            SideCrossIterator begin() const {
                return SideCrossIterator(head);
            }

            // Create an SideCrossIterator pointing to the end of the linked list
            SideCrossIterator end() const {
                return nullptr;
            }
        };

        class PrimeIterator {
        private:
            Node* head;
            Node* current;
            int index;

        public:
            PrimeIterator(Node* node) : head(node), current(node), index(0) {}
            // Constructor that takes a MagicalContainer object as an argument
            PrimeIterator(const MagicalContainer& container) : head(container.getHeadPrime()), current(container.getHeadPrime()), index(0) {}

            PrimeIterator& operator=(const PrimeIterator &other) {
                if (this != &other)
                {
                    if (head != other.head && head != nullptr && other.head != nullptr)
                        throw std::runtime_error("Cannot assign iterators from different containers");

                    head = other.head;
                    index = other.index;
                    current = other.current;
                }

                return *this;
            }

            // Dereference operator
            int& operator*() {
                return current->value;
            }

            // Pre-increment operator
            PrimeIterator& operator++() {
                if (current != nullptr) {
                    current = current->nextInPrimeContainer;
                    index++;
                }
                else{
                    throw std::runtime_error("runtime_error: Iterator out of range");
                }
                return *this;
            }

            // Equality comparison operator
            bool operator==(const PrimeIterator& other) const {
                return current == other.current;
            }

            // Inequality comparison operator
            bool operator!=(const PrimeIterator& other) const {
                return !(*this == other);
            }

            // Greater than comparison operator
            bool operator>(const PrimeIterator& other) const {
                return index > other.index;
            }

            // Less than comparison operator
            bool operator<(const PrimeIterator& other) const {
                return index < other.index;
            }

            // Create an PrimeIterator pointing to the beginning of the linked list
            PrimeIterator begin() const {
                return PrimeIterator(head);
            }

            // Create an PrimeIterator pointing to the end of the linked list
            PrimeIterator end() const {
                return nullptr;
            }
        };
        
        // Default constructor
        MagicalContainer() : head(nullptr), headAscend(nullptr), headSidecross(nullptr), headPrime(nullptr), containerSize(0), primeContainerSize(0) {}

        // Copy constructor
        MagicalContainer(const MagicalContainer& other) {
            if (other.head != nullptr) {
                head = new Node(other.head->value);
                Node* currentNode = head;
                Node* otherNode = other.head->nextInContainer;

                while (otherNode != nullptr) {
                    currentNode->nextInContainer = new Node(otherNode->value);
                    currentNode = currentNode->nextInContainer;
                    otherNode = otherNode->nextInContainer;
                }
            }
        }

        // Destructor
        ~MagicalContainer() {
            Node* current = head;
            while (current != nullptr) {
                Node* nextInContainer = current->nextInContainer;
                delete current;
                current = nextInContainer;
            }
        }

        // Assignment operator
        MagicalContainer& operator=(const MagicalContainer& other) {
            if (this != &other) {
                MagicalContainer temp(other);
                std::swap(head, temp.head);
            }
            return *this;
        }

        Node* getHeadAscend() const {
            return headAscend;
        }
        Node* getHeadSidecross() const {
            return headSidecross;
        }
        Node* getHeadPrime() const {
            return headPrime;
        }

        // Equality comparison operator
        bool operator==(const MagicalContainer& other) const {
            Node* current1 = head;
            Node* current2 = other.head;

            while ((current1 != nullptr) && (current2!= nullptr)) {
                if (current1->value != current2->value) {
                    return false;
                }
                current1 = current1->nextInContainer;
                current2 = current2->nextInContainer;
            }

            return current1 == nullptr && current2 == nullptr;
        }

        // Inequality comparison operator
        bool operator!=(const MagicalContainer& other) const {
            return !(*this == other);
        }

        int size (){
            return containerSize;
        }
        int primeSize (){
            return primeContainerSize;
        }

        // Helper function to insert a node into a linked list
        void insertNode(Node* newNode) {
            if (!head || newNode->value < head->value) {
                newNode->nextInContainer = head;
                head = newNode;
            }
            else {
                Node* current = head;
                while (current->nextInContainer) {
                    current = current->nextInContainer;
                }
                newNode->nextInContainer = current->nextInContainer;
                current->nextInContainer = newNode;
            }
        }

        // Helper function to insert a node into the nextInAscendingContainer list
        void insertNodeAscending(Node* newNode) {
            if (!headAscend || newNode->value < headAscend->value) {
                newNode->nextInAscendingContainer = headAscend;
                headAscend = newNode;
            }
            else {
                Node* currentAsc = headAscend;
                while (currentAsc->nextInAscendingContainer && currentAsc->nextInAscendingContainer->value < newNode->value) {
                    currentAsc = currentAsc->nextInAscendingContainer;
                }
                newNode->nextInAscendingContainer = currentAsc->nextInAscendingContainer;
                currentAsc->nextInAscendingContainer = newNode;
            }
        }

        // Helper function to insert a node into the nextInPrimeContainer list (if prime)
        void insertNodePrime(Node* newNode) {
            if (!headPrime || newNode->value < headPrime->value) {
                newNode->nextInPrimeContainer = headPrime;
                headPrime = newNode;
            }
            else {
                Node* currentPrime = headPrime;
                while (currentPrime->nextInPrimeContainer && currentPrime->nextInPrimeContainer->value < newNode->value) {
                    currentPrime = currentPrime->nextInPrimeContainer;
                }
                newNode->nextInPrimeContainer = currentPrime->nextInPrimeContainer;
                currentPrime->nextInPrimeContainer = newNode;
            }
        }

        // Helper function to insert a node into the nextInSidecrossContainer list
        void insertNodeSidecross(Node* newNode) {
            if (!headSidecross) {
                headSidecross = newNode;
            }
            else {
                Node* current = headSidecross;
                Node* temp = nullptr;
                newNode->nextInSidecrossContainer = current->nextInSidecrossContainer;
                current->nextInSidecrossContainer = newNode;
                current = current->nextInSidecrossContainer;

                while (current->nextInSidecrossContainer && current->nextInSidecrossContainer->nextInSidecrossContainer) {
                    temp = current->nextInSidecrossContainer;
                    current->nextInSidecrossContainer = current->nextInSidecrossContainer->nextInSidecrossContainer;
                    temp->nextInSidecrossContainer = current->nextInSidecrossContainer->nextInSidecrossContainer;
                    current->nextInSidecrossContainer->nextInSidecrossContainer = temp;
                    current = current->nextInSidecrossContainer->nextInSidecrossContainer;
                }
            }
        }

        // Main addElement function
        void addElement(int value) {
            containerSize++;
            Node* newNode = new Node(value);

            insertNode(newNode);
            insertNodeAscending(newNode);

            if (isPrime(value)) {
                primeContainerSize++;
                insertNodePrime(newNode);
            }

            insertNodeSidecross(newNode);
        }
        Node* findNode(int value) {
            Node* current = head;
            while (current != nullptr && current->value != value) {
                current = current->nextInContainer;
            }
            return current;
        }

        void updateContainerPointers(Node* current) {
            Node* previous = findPreviousNode(current, head);
            if (previous != nullptr) {
                previous->nextInContainer = current->nextInContainer;
            } else {
                head = current->nextInContainer;
            }
        }

        void updateAscendContainerPointers(Node* current) {
            Node* previous = findPreviousNode(current, headAscend);
            if (previous != nullptr) {
                previous->nextInAscendingContainer = current->nextInAscendingContainer;
            } else {
                headAscend = current->nextInAscendingContainer;
            }
        }

        void updatePrimeContainerPointers(Node* current) {
            Node* previous = findPreviousNode(current, headPrime);
            if (previous != nullptr) {
                previous->nextInContainer = current->nextInContainer;
            } else {
                headPrime = current->nextInContainer;
            }
        }

        void updateSidecrossContainerPointers(Node* current) {
            Node* previous = findPreviousNode(current, headSidecross);
            if (previous != nullptr) {
                previous->nextInSidecrossContainer = current->nextInSidecrossContainer;
                Node* temp = nullptr;
                while (current->nextInSidecrossContainer && current->nextInSidecrossContainer->nextInSidecrossContainer) {
                    temp = current->nextInSidecrossContainer;
                    current->nextInSidecrossContainer = current->nextInSidecrossContainer->nextInSidecrossContainer;
                    temp->nextInSidecrossContainer = current->nextInSidecrossContainer->nextInSidecrossContainer;
                    current->nextInSidecrossContainer->nextInSidecrossContainer = temp;
                    current = current->nextInSidecrossContainer->nextInSidecrossContainer;
                }
            } else {
                headSidecross = current->nextInSidecrossContainer;
            }
        }

        Node* findPreviousNode(Node* current, Node* start) {
            Node* previous = nullptr;
            Node* temp = start;
            while (temp != nullptr && temp != current) {
                previous = temp;
                temp = temp->nextInContainer;
            }
            return previous;
        }

                void removeElement(int value) {
            if (head == nullptr) {
                return;
            }

            Node* current = findNode(value);
            if (current == nullptr) {
                throw std::runtime_error("runtime error: Element not found");
            }

            updateContainerPointers(current);
            updateAscendContainerPointers(current);
            if (isPrime(value)) {
                updatePrimeContainerPointers(current);
            }
            updateSidecrossContainerPointers(current);

            delete current;
            containerSize--;
        }
    };
}
