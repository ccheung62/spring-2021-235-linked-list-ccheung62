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
  if (loc == 0){
    insert(data);
    return;
  }
  Node *walker = head;
  for(int i=0; i<loc-1; i++){
    walker = walker->getNext();
  }
  Node *new_node = new Node(data);
  new_node->setNext(walker->getNext());
  walker->setNext(new_node);
}

void List::remove(int loc){
  if (loc == 0){
    head = head->getNext();
    return;
  }
  Node *walker = head;
  for(int i=0; i<loc-1; i++){
    walker = walker->getNext();
  }
  walker->setNext(walker->getNext()->getNext());
  walker = walker->getNext();
  walker = nullptr;
  delete walker;
}

std::string List::get(int loc){
  if (loc < 0 || head == nullptr){
    return "location specified is out of bound";
  }
  Node *walker = head;
  for(int i=0; i<loc; i++){
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