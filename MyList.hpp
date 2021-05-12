//
//  MyList.hpp
//  przychodnia
//
//  Created by Alexander on 05/05/2021.
//

#ifndef MyList_hpp
#define MyList_hpp

#include <iostream>
#include <stdio.h>

template<class Type> class MyList {
private:
    class Node;
    friend class Node;
    
    Node* head;
    const int max_nodes;
    
    class Node {
    public:
        friend class MyList;
        Node* next;
        Type data;
        Node(Type dat): next(NULL) { data = dat; }
        ~Node() {};
    };
public:
    int nodesCnt;
    
    MyList(int max = 30): head(NULL), nodesCnt(0), max_nodes(max) {}
    ~MyList() {}
    
    // FUNCTIONS
    bool queue(Type data);
    Type dequeue();
    MyList& operator=(const MyList& rv);
    
    bool isEmpty() {
        if(head == NULL)
            return true;
        else
            return false;
    }
    
    Node* return_head() {return head;}
};


template<class Type>
bool MyList<Type>::queue(Type data) {
    if(nodesCnt < max_nodes) {
        if(head == NULL)
            head = new Node(data);
        else {
            Node* current = head;
            while(current->next != NULL)
                current = current->next;
            
            current->next = new Node(data);
        }
        nodesCnt++;
        return true;
    }
    else
        return false;
}


template<class Type>
Type MyList<Type>::dequeue() {
    if(head == NULL)
        return Type();
    else {
        Node* current = head;
        Node* prev = head;
        Type temp;
        
        if(head->next == NULL) {
            temp = head->data;
            delete head;
            head = NULL;
            nodesCnt--;
            return temp;
        }
        
        while(current->next != NULL) {
            prev = current;
            current = current->next;
        }
        temp = current->data;
        
        delete(current);
        prev->next = NULL;
        nodesCnt--;
        return temp;
    }
}

template<class Type>
MyList<Type>& MyList<Type>::operator=(const MyList& rv) {
    std::cout << "Wywołuję mój operator przypisania\n" << std::endl;
    if(rv.head != NULL) {
        head = new Node(rv.head->data);
        assert(head != rv.head);
        
        Node* current_new = head;
        Node* current = rv.head;
        while(current->next != NULL) {
            current_new->next = new Node(current->next->data);
            current_new = current_new->next;
            
            current = current->next;
        }
        nodesCnt = rv.nodesCnt;
    }
    return *this;
}

#endif /* MyList_hpp */
