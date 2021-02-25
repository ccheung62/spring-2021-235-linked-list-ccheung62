#include <iostream>
#include "List.h"

int main(int argc, char *argv[]){
  List *l1 = new List();
  l1->insert("e");
  l1->insert("d");
  l1->insert("c");
  l1->insert("b");
  l1->insert("a");
  std::cout << "The current list is:\n   ";
  std::cout << l1->toString() << std::endl;
  std::cout << "\nAfter inserting \"x\" at location 2\n   ";
  l1->insert(2,"x");
  std::cout << l1->toString() << std::endl;
  std::cout << "\nAfter removing Node at location 2\n   ";
  l1->remove(2);
  std::cout << l1->toString() << std::endl;
  std::cout << "\nThe data at location 2 is " << l1->get(2) << std::endl;
  std::cout << "For the Node at location -1, " << l1->get(-1) << std::endl;
  std::cout << "For the Node at location 5, " << l1->get(5) << std::endl;
  std::cout << "Deleting the list..." << std::endl;
  l1->~List();
  return 0;

}
