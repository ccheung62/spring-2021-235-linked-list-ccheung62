#include <iostream>
#include "List.h"
#include "DList.h"

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
  std::cout << "Creating new Double linked Node List" << std::endl;
  DList *l2 = new DList();
  l2->insert(0, "a");
  l2->insert(1, "b");
  l2->insert(2, "d");
  l2->insert(3, "e");
  l2->insert(4, "f");
  l2->insert(2, "c");
  std::cout << "The current list is:\n   ";
  std::cout << l2->toString() << std::endl;
  std::cout << "\nAfter inserting \"x\" at location 2\n   ";
  l2->insert(2,"x");
  std::cout << l2->toString() << std::endl;
  std::cout << "\nAfter removing Node at location 2\n   ";
  l2->remove(2);
  std::cout << l2->toString() << std::endl;
  std::cout << "\nThe data at location 2 is " << l2->get(2) << std::endl;
  std::cout << "For the Node at location -1, " << l2->get(-1) << std::endl;
  std::cout << "For the Node at location 5, " << l2->get(5) << std::endl;
  std::cout << "Deleting the list..." << std::endl;
  l2->~DList();

  return 0;

}
