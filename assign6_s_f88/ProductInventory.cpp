/*File Name: ProductInventory.cpp
 
 Author: Shane Fleming
 Date: 04/07/16
 Assignment Number: 6
 CS 2308.257 Spring 2016
 Instructor: Jill Seaman
 
 Store Inventory, Constructor, destructor, and functions for editing inventory*/

#include <iostream>
#include <iomanip>
using namespace std;

#include "ProductInventory.h"

/*****************************************************************************
 ProductInventory: Constructor creates head productList
 returns: NO RETURN
 ****************************************************************************/

ProductInventory::ProductInventory()
{
    productList = NULL;
}

/*****************************************************************************
 ~ProductInventory: Destroy head productList
 returns: NO RETURN
 ****************************************************************************/

ProductInventory::~ProductInventory()
{
    ProductNode *p = productList;  //pointer to head
    ProductNode *n;                //pointer to save location
    while (p!=NULL)
    {
        n = p->next;  //save address of next node
        delete p;
        p = n;     //make p point to the next node
    }
}

/*****************************************************************************
 addProduct: Input validation
 Product p, passes Product as pa
 returns: bool, false if duplicate, or not "invalid", else true
 ****************************************************************************/

bool ProductInventory::addProduct(Product pa)
{
    ProductNode *newNode;       //pointer to newNode
    
    newNode = new ProductNode;
    newNode->data = pa;
    newNode->next = NULL;
    
    if (productList==NULL)
    {
        productList = newNode;
    }
    else {
        ProductNode *p = productList;
        
        while (p->next != NULL)
        {
            if(pa.isEqual(p->data))
            {
                return false;
            }
            
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
    ProductNode* iter = productList;  //pointer to head
    ProductNode* prev;                //pointer to previous node
    
    while(iter != NULL && (iter->data.getProductName() != testName ||
                           iter->data.getLocator() != testLoc))
    {
        prev = iter;
        iter = iter->next;
    }
    
    if(iter == NULL)
    {
        return false;
    }
    
    if(iter == productList)
    {
        productList = iter->next;
    }
    else
    {
        prev->next = iter->next;
    }
    
    delete iter;
    
    return true;
}

/*****************************************************************************
 showInventory: displays all of inventory
 returns: NO RETURN Void Function
 ****************************************************************************/

void ProductInventory::showInventory()
{
    ProductNode *p = productList;  //points to head
    
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
    double total = 0;               //running total of quantity for inventory
    ProductNode *p = productList;   //points at head
    
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

Product ProductInventory::findMinimum()
{
    ProductNode* iter = productList;    //points at head
    Product* min = NULL;                //points at NULL, checks if at end
    
    while (iter != NULL)
    {
        if (min == NULL || min->greaterThan(iter->data))
        {
            min = &iter->data;
        }
        
        iter = iter->next;
    }
    
    return min == NULL ? Product() : *min;
}

/*****************************************************************************
 sortInventory: sorts inventory
 returns: NO RETURN Void Function
 ****************************************************************************/

void ProductInventory::sortInventory()
{
    ProductNode* newList = NULL;    //points at NULL, transition
    ProductNode* temp = NULL;       //points at NULL, space holder
    
    if (productList == NULL)
    {
        return;
    }
    
    // Just move temp up the new list each iteration, appending a new node
    // with the minimum
    while (productList != NULL)
    {
        // Check for the head of the new list
        if (temp == NULL)
        {
            temp = new ProductNode;
            newList = temp;
        }
        else
        {
            temp->next = new ProductNode;
            temp = temp->next;
        }
        
        temp->next = NULL;
        temp->data = findMinimum();
        
        // Remove old ProductNode
        removeProduct(temp->data.getProductName(), temp->data.getLocator());
    }
    
    productList = newList;
}
