#ifndef DSList_H
#define DSList_H

/**
 * @brief Singly-linked list that uses position
 *
 * Implement all described functions and provide a test program using CATCH2
 * 
 * @tparam Object 
 */
template <typename Object>
class DSList
{
private:
   /**
     * @brief The nested Node data structure
     * 
     * struct is in C++ a class with all public members
     */
    struct Node
    {
        Object data;
        Node *next;

        Node(const Object &d = Object{}, Node *n = nullptr)
            : data{d}, next{n} {};
    };
    
    Node *head;

public:

// You need to implement at least:
// Default constructor--------------------------------------------------------------------------------------------------
DSList() {
    head = nullptr;
}

// Rule-of-3------------------------------------------------------------------------------------------------------------
    //Destructor
    ~DSList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
    //Copy Constructor
    DSList(const DSList& copy) {
        head = nullptr;
        Node* current = copy.head;
        while (current != nullptr) {
            push_back(current->data);
            current = current->next;
        }
    }
    //Copy Assignment Operator
    DSList<Object>& operator=(const DSList<Object>& theNode) {
        // Delete the old list
        empty();
        head = nullptr;
        // Copy the new list
        Node* current = theNode.head;
        while (current != nullptr) {
            push_back(current->data);
            current = current->next;
        }

        return *this;
    }

// size-----------------------------------------------------------------------------------------------------------------
size_t size() const {

    //Consider special cases of empty list!!!

    size_t size = 0;
    Node* current = head;

    while(current != nullptr) {
        size++;
        current = current->next;
    }

    return (size);
}

// is the list empty?---------------------------------------------------------------------------------------------------
bool is_empty() const {
    return (head == nullptr);
}

// clear the whole list-------------------------------------------------------------------------------------------------
void empty() {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = NULL;
}

// find an element with a specific value (and return the position. First element in list is pos 0). Not found returns -1.
int find(Object val) {
    Node* current = head;
    int pos = 0;
    while (current != NULL) {
        if (current->data == val) {
            return pos;
        }
        current = current->next;
        pos++;
    }
    return -1;
}

// insert at the beginning of the list (push_front).--------------------------------------------------------------------
void push_front(const Object& data) {
    // 1. Allocate new node
    Node* newNode = new Node();
    newNode->data = data;
    // 2. Find: we know it goes right after head
    // 3. Link new node
    newNode->next = head;
    head = newNode;
}

// insert at the end of the list (push_back).---------------------------------------------------------------------------
void push_back(const Object& data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// remove the first element(pop_front)----------------------------------------------------------------------------------
void pop_front() {
    //1. Find location (no work for front)

    //2. Unlink Node
    Node* old_head = head;
    head = head->next;

    //3. Deallocate Node
    delete old_head;
}

// remove the last element (pop_back)-----------------------------------------------------------------------------------
void pop_back() {
    if (head == nullptr) {
        return;
    } else if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
}

//Look at the first element in the Front of the List--------------------------------------------------------------------
const Object& front() const {
    if (!is_empty()) {
        return (head->data);
    } else {
        throw std::out_of_range("List is empty");
    }

}

//Print (operator<< would be nicer)
void print() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
}

};

#endif
