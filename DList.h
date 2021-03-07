#pragma once
#include "Dnode.h"

class DList{
private:
    Dnode *head;
    Dnode *tail;
    Dnode *cur;
    int size;
    int curI;
  
public:
    DList();
    std::string toString();
    void insert(int loc, std::string data);
    void remove(int loc);
    std::string get(int loc);
    Dnode *searchForLoc(int l);
    ~DList();
};