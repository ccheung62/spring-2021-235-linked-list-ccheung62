#include <iostream>
#include <cmath>
#include "DList.h"

DList::DList(){
    head = nullptr;
    tail = nullptr;
    curI = 0;
    size = 0;
}

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

Dnode *DList::searchForLoc(int l){
    //finding the closest entry point
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
        cur = walker;
        curI = loc;
    }
    size--;
}

std::string DList::get(int loc){
    if (loc >= size || loc < 0){
        return "location specified is out of bound";
    }
    Dnode *walker = searchForLoc(loc);
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

