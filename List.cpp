#include <iostream>
#include "List.h"

List::List(){
  head = nullptr;
}

void List::insert(std::string data){
  // create a new node
  Node *new_node = new Node(data);

  // insert the new node
  new_node->setNext(head);
  head=new_node;
}

void List::insert(int loc, std::string data){
  //if inserting at the beginnning
  if (loc == 0){
    insert(data);
    return;
  }
  //if out of bound
  if (loc < 0){
    return;
  }
  //if out of bound
  if (loc == 1 && head == nullptr){
    return;
  }
  Node *walker = head;
  for(int i=0; i<loc-1; i++){
    //check if out of bound
    if (walker == nullptr){
      return;
    }
    walker = walker->getNext();
    //see if loc is nullptr
    if(walker == nullptr){
      //see if they are trying to insert at the end of the list
      if (loc-i>1){
        return;
      }
    }
  }
    Node *new_node = new Node(data);
    new_node->setNext(walker->getNext());
    walker->setNext(new_node);
}

void List::remove(int loc){
  if (head == nullptr || loc < 0){
    //if it is an empty list or out of bound
    return;
  }
  if (loc == 0){
    //moves the head up by one
    head = head->getNext();
    return;
  }
  if (loc == 1){
    if (head->getNext() == nullptr){
      //if the list only have one Node
      return;
    }
    else {
      Node *temp = head->getNext()->getNext();
      //if there is only two Node in the list
      if (temp == nullptr){
          head->setNext(nullptr);
          delete temp;
          return;
      }
    }
  }
  Node *walker = head;
  for(int i=0; i<loc-1; i++){
    walker = walker->getNext();
    //see if the location before loc is nullptr
    if(walker != nullptr){
      Node *temp = walker->getNext();
      //see if loc is nullptr
      if (temp != nullptr){
        temp = walker->getNext();
        //see if location after loc is nullptr
        if (temp != nullptr){}
        else{
          walker->setNext(nullptr);
          delete temp;
          return;
        }
      }
      else {
        return;
      }
    }
    else {
      return;
    }
  }
  //links the before loc to the after loc
  walker->setNext(walker->getNext()->getNext());
  walker = walker->getNext();
  walker = nullptr;
  delete walker;
}

std::string List::get(int loc){
  //check if out of bound
  if (loc < 0 || head == nullptr){
    return "location specified is out of bound";
  }
  Node *walker = head;
  for(int i=0; i<loc; i++){
    //check if out of bound
    if (walker->getNext() == nullptr){
      return "location specified is out of bound";
    }
    walker = walker->getNext();
  }
  return walker->getData();
}

std::string List::toString(){
  Node *walker = head;
  std::string s = "";
  while (walker != nullptr){
    s = s + walker->getData() + "-->";
    walker = walker->getNext();
    
  }
  s=s+"nullptr";
  return s;
}

List::~List(){
  Node *first = head;
  Node *sec = first->getNext();
  while(sec != nullptr){
    first = sec;
    sec = sec->getNext();
    first = nullptr;
    delete first;
  }
  head = nullptr;
  delete head;
}