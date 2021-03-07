#include <iostream>
#include <cmath>
#include "DList.h"

DList::DList(){
    head = nullptr;
    tail = nullptr;
    curI = 0;
    size = 0;
}

/* This function returns the entire list as a string */
std::string DList::toString(){
    std::string result =  "head-->";
    Dnode *walker = head;
    for(int i=0; i<size-1;i++){
        result += walker->getData() + "<-->";
        walker = walker->getNext();
    }
    result += walker->getData() + "<--tail";
    return result;
}

/* This function finds the closest entry point from head, cur, and tail 
then moves a pointer Dnode until it reaches the specified location */
Dnode *DList::searchForLoc(int l){
    int min = l-0;
    int start = 0;
    Dnode *walker = head;
    if (abs(l-curI) < min){
        start = curI;
        walker = cur;
    }
    if (abs(l-size) < min){
        start = size-1;
        walker = tail;
    }
    bool up = (l-start >= 0);
    //loops until walker reaches loc
    while(start != l){
        if (up){
            walker = walker->getNext();
            start++;
        }
        else {
            walker = walker->getPrev();
            start--;
        }
    }
    return walker;
}

/*This function insert data into a new node at location loc. 
SearchForLoc(int l) is used for optimization. 
cur is pointed to the newly inserted node at the end. */
void DList::insert(int loc, std::string data){
    //if they are inserting at the beginning 
    if (loc == 0){
        Dnode *new_dnode = new Dnode (data);
        if (size > 0){
            new_dnode ->setNext(head);
            head->setPrev(new_dnode);
        }
        //if it is the first node on the list
        else {
            tail = new_dnode;
        }
        head = new_dnode;
        cur = head;
        curI = 0;
        size++;
        return;
    }
    //if out of bound
    if (loc > size || loc < 0){
        return;
    }
    //moving to one before the loc 
    loc--;
    Dnode *walker = searchForLoc(loc);
    Dnode *new_dnode = new Dnode(data);
    if (walker->getNext() != nullptr){
        walker->getNext()->setPrev(new_dnode);
        new_dnode->setNext(walker->getNext());
    }
    else {
        tail = new_dnode;
    }
    walker->setNext(new_dnode);
    new_dnode->setPrev(walker);
    size++;
    cur = new_dnode;
    curI = loc+1;
}

/*This function removes the node at loc from the list. 
SearchForLoc(int l) is used for optimization. 
cur is pointed to the node after the one removed.*/
void DList::remove(int loc){
    //if out of bound
    if (loc >= size || loc < 0){
        return;
    }
    Dnode *walker = searchForLoc(loc);
    //if removing the first node
    if (walker->getPrev() == nullptr){
        head = walker->getNext();
        head->setPrev(nullptr);
        cur = head;
        curI = 0;
        walker = nullptr;
        delete walker;
    }
    //if removing the last node
    else if(walker->getNext() == nullptr){
        tail = walker->getPrev();
        tail->setNext(nullptr);
        cur = tail;
        curI = size-1;
        walker = nullptr;
        delete walker;
    }
    else{
        walker->getPrev()->setNext(walker->getNext());
        walker->getNext()->setPrev(walker->getPrev());
        cur = walker->getNext();
        curI = loc;
    }
    size--;
}

/* This function returns the value at location loc. 
SearchForLoc(int l) is used for optimization. 
cur is pointed at the node specified */
std::string DList::get(int loc){
    if (loc >= size || loc < 0){
        return "location specified is out of bound";
    }
    Dnode *walker = searchForLoc(loc);
    cur = walker;
    curI = loc;
    return walker->getData();
}

DList::~DList(){
    Dnode *walker = head;
    while(head->getNext() != nullptr){
        head = head->getNext();
        walker = head->getPrev();
        walker->~Dnode();
    }
    std::cout << "Finished deleting the DList" << std::endl;
}

