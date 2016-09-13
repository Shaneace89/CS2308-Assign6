//ListDriver.cpp: using NumberList

#include <iostream>
#include "NumberList.h"

int main() {
    
    // set up the list
    NumberList list;
    
    //Append Some values to the list
    list.appendNode(2.5);
    list.appendNode(7.9);
    list.appendNode(12.6);
    
    
    // Display the values in the list
    list.displayList();
    
    // Demo insert:
    list.insertNode (8.5);
    list.displayList();

    list.insertNode (1.5);
    list.displayList();

    list.insertNode (21.5);
    list.displayList();

    // Demo delete:
    cout << endl << "remove 7.9:" << endl;
    list.deleteNode(7.9);
    list.displayList();
    
    cout << endl << "remove 8.9: " << endl;
    list.deleteNode(8.9);
    list.displayList();
    
    cout << endl << "remove 2.5: " << endl;
    list.deleteNode(2.5);
    list.displayList();

    
}