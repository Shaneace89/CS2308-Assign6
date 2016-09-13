// file NumberList.cpp

#include <iostream>
using namespace std;

#include "NumberList.h"

NumberList::NumberList() {
    
    head = NULL;
}


NumberList::~NumberList() {
    
    ListNode *p = head;
    ListNode *n;
    while (p!=NULL) {
        n = p->next;  //save address of next node
        delete p;
        p = n;     //make p point to the next node
    }
    
    
}

void NumberList::appendNode(double num) {
    
    ListNode *newNode;
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = NULL;
    
    if (head==NULL)
        head = newNode;
    
    else {
        ListNode *p = head;
        while (p->next!=NULL) {
            p = p->next;
        }
        // now p points to the last node
        p->next = newNode;
    }
    
}

void NumberList::insertNode(double num) {
    
    //make new node
    ListNode *newNode = new ListNode;
    newNode->value = num;

    //set up pointers
    ListNode *p = head;
    ListNode *n;
    
    //advance ponters through list to insertion point
    while (p && p->value<num) {
        n = p;
        p = p->next;
    }
    
    //change pointers to include new node
    if (p==head) {
        head = newNode;
        newNode->next = p;
    } else {
        n->next=newNode;
        newNode->next = p;
    }

}

void NumberList::deleteNode(double num) {
    
    ListNode *p = head;   // to traverse the list
    ListNode *n;          // trailing node pointer
    
    // skip nodes not equal to num, stop at last
    while (p && p->value!=num) {
        n = p;        // save it!
        p = p->next;  // advance it
    }
    
    // p not null: num is found, set links + delete
    if (p) {
        if (p==head) {   // p points to the first elem.
            head = p->next;
            delete p;
        } else {         // n points to the predecessor
            n->next = p->next;
            delete p;
        }
    }
}

void NumberList::displayList() {
    
    ListNode *p = head;
    while (p!=NULL) {
        cout << p->value  << "  ";
        p = p->next;
    }
    cout << endl;
    
}
