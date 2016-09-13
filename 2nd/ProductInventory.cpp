/*File Name: ProductInventory.cpp
 
 Author: Shane Fleming
 Date: 04/07/16
 Assignment Number: 6
 CS 2308.257 Spring 2016
 Instructor: Jill Seaman
 
 Store Inventory, One constructors and functions for editing inventory*/

#include <iostream>
#include <iomanip>
using namespace std;

#include "ProductInventory.h"

/*****************************************************************************
 ProductInventory: Constructor creates array of Products the desired size
 returns: NO RETURN
 ****************************************************************************/

ProductInventory::ProductInventory()
{
    productList = NULL;
}

/*****************************************************************************
 ~ProductInventory: Destroy products array
 returns: NO RETURN
 ****************************************************************************/

ProductInventory::~ProductInventory()
{
    ProductNode *p = productList;
    ProductNode *n;
    while (p!=NULL)
    {
        n = p->next;  //save address of next node
        delete p;
        p = n;     //make p point to the next node
    }
}

/*****************************************************************************
 addProduct: Inpute validation, call resize if full
 Product p, passes Product as p
 returns: bool, false if duplicate, or not "invalid", else true
 ****************************************************************************/

bool ProductInventory::addProduct(Product pa)
{
    ProductNode *newNode;
    newNode = new ProductNode;
    newNode->data = pa;
    newNode->next = NULL;
    
    if (productList==NULL)
        productList = newNode;
    
    else {
        ProductNode *p = productList;
        while (p->next!=NULL)
        {
            p = p->next;
        }
        // now p points to the last node
        p->next = newNode;
    }
    return true;
}

/*****************************************************************************
 removeProduct: removes desired product
 string testName, passes name for desired remove product
 string testLoc, passes location for desired remove product
 returns: bool, if found returns true, else false
 ****************************************************************************/

bool ProductInventory::removeProduct(string testName, string testLoc)
{
    ProductNode *p = productList;   // to traverse the list
    ProductNode *n;          // trailing node pointer
    
    // skip nodes not equal to num, stop at last
   while (p && p->data.getProductName()!= testName)
    {
        n = p;        // save it!
        p = p->next;  // advance it
    }
    
    // p not null: num is found, set links + delete
    if (p)
    {
        if (p == productList)
        {   // p points to the first elem.
            productList = p->next;
            delete p;
            return true;
        }
        else
        {   // n points to the predecessor
            n->next = p->next;
            delete p;
            return true;
        }
    }
    return false;
}

/*****************************************************************************
 showInventory: displays all of inventory
 returns: NO RETURN Void Function
 ****************************************************************************/

void ProductInventory::showInventory()
{
    ProductNode *p = productList;
    while (p!=NULL)
    {
        cout << p->data.getLocator() << "  "
        << p->data.getQuantity() << "  $"
        << setprecision(2) << fixed
        << p->data.getPrice() << "  "
        << setprecision(1) << fixed
        << p->data.getProductName() << endl;
        
        p = p->next;
    }
    cout << endl;
}

/*****************************************************************************
 getTotal: adds the quantity of all products
 returns: sum of all quantity
 ****************************************************************************/

int ProductInventory::getTotalQuantity()
{
    double total = 0;
    ProductNode *p = productList;
    
    while (p!=NULL)
    {
        total += p->data.getQuantity();
        
        p = p->next;
    }

    return total;
}

/*****************************************************************************
 findMinimum: Checks if one name/loc is less than another
 returns: bool, true if name is greater, or if name same, but loc greater
 ****************************************************************************/

//************MATT THIS FUNCITION*******************

Product ProductInventory::findMinimum()
{
    ProductNode *p = productList;
    ProductNode *n = productList; n = n->next;
    
    while ( n != NULL && p != NULL)
    {
        
    if (p->data.getProductName() == n->data.getProductName())
    {
        if (p->data.getLocator() < n->data.getLocator())
            p = p->next->next;
        else
            n = n->next;
    }
    
    else
    {
    if (p->data.getProductName() < n->data.getProductName())
        p = p->next->next;
    else
        n = n->next;
    }
    }
    
    if (p->data.getProductName() < n->data.getProductName())
        return p->data;
    else
        return n->data;
}

/*****************************************************************************
 sortInventory: sorts inventory
 returns: NO RETURN Void Function
 ****************************************************************************/

void ProductInventory::sortInventory()
{
    /*
    int y = 1;  //counters to cycle array
    
    for(int i = 0; i < count; i++)
    {
        if(findMinimum())
        {
            products[size+1] = products[i];
            products[i] = products[y];
            products[y] = products[size+1];
            y++;
        }
        else
            y++;
    }
     */
}