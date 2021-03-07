#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "List.h"
#include "DList.h"

List *l = new List();
// List test cases
//insert function
TEST_CASE("List: Insert function"){
    l->insert(0,"b");
    CHECK(l->toString() == "b-->nullptr");
    l->insert(1,"c");
    CHECK(l->toString() == "b-->c-->nullptr");
    l->insert(0,"a");
    CHECK(l->toString() == "a-->b-->c-->nullptr");
}

TEST_CASE("List: Insert function - out of bounds"){
    l->insert(10, "x");
    CHECK(l->toString() == "a-->b-->c-->nullptr");
    l->insert(-10, "x");
    CHECK(l->toString() == "a-->b-->c-->nullptr");
    l->insert(-1, "x");
    CHECK(l->toString() == "a-->b-->c-->nullptr");
    l->insert(4, "x");
    CHECK(l->toString() == "a-->b-->c-->nullptr");
}

TEST_CASE ("List: Insert function - at the end"){
    l->insert(3, "d");
    CHECK(l->toString() == "a-->b-->c-->d-->nullptr");
    l->insert(4,"e");
    CHECK(l->toString() == "a-->b-->c-->d-->e-->nullptr");
    l->insert(5,"f");
    CHECK(l->toString() == "a-->b-->c-->d-->e-->f-->nullptr");
}

//get function
TEST_CASE("List: Get function"){
    CHECK(l->get(2) == "c");
    CHECK(l->get(0) == "a");
    CHECK(l->get(5) == "f");
}

TEST_CASE("List: Get function - out of bounds"){
    CHECK(l->get(6) == "location specified is out of bound");
    CHECK(l->get(-1) == "location specified is out of bound");
    CHECK(l->get(-10) == "location specified is out of bound");
    CHECK(l->get(10) == "location specified is out of bound");
}

//remove function
TEST_CASE ("List: Remove function"){
    l->remove(0);
    CHECK(l->toString() == "b-->c-->d-->e-->f-->nullptr");
    l->remove(1);
    CHECK(l->toString() == "b-->d-->e-->f-->nullptr");
    l->remove(3);
    CHECK(l->toString() == "b-->d-->e-->nullptr");
}

TEST_CASE("List: Remove function - out of bound"){
    l->remove(-10);
    CHECK(l->toString() == "b-->d-->e-->nullptr");
    l->remove(10);
    CHECK(l->toString() == "b-->d-->e-->nullptr");
    l->remove(-1);
    CHECK(l->toString() == "b-->d-->e-->nullptr");
    l->remove(3);
    CHECK(l->toString() == "b-->d-->e-->nullptr");
}

List *le = new List();
TEST_CASE ("List: Remove function - No Nodes"){
    le->remove(0);
    CHECK(le->toString() == "nullptr");
    le->remove(1);
    CHECK(le->toString() == "nullptr");
    le->remove(2);
    CHECK(le->toString() == "nullptr");
}

TEST_CASE("List: Insert function - No Nodes"){
    le->insert(2, "x");
    CHECK(le->toString() == "nullptr");
    le->insert(1, "x");
    CHECK(le->toString() == "nullptr");
    le->insert(0, "x");
    CHECK(le->toString() == "x-->nullptr");
}

TEST_CASE("List: Remove function - One Node"){
    le->remove(2);
    CHECK(le->toString() == "x-->nullptr");
    le->remove(1);
    CHECK(le->toString() == "x-->nullptr");
    le->remove(0);
    CHECK(le->toString() == "nullptr");
}

TEST_CASE("List: Insert function - One Node"){
    le->insert(0, "a");
    le->insert(10, "x");
    CHECK(le->toString() == "a-->nullptr");
    le->insert(-10, "x");
    CHECK(le->toString() == "a-->nullptr");
    le->insert(-1, "x");
    CHECK(le->toString() == "a-->nullptr");
    le->insert(1, "x");
    CHECK(le->toString() == "a-->x-->nullptr");
    le ->remove(1);
    le->insert(0, "x");
    CHECK(le->toString() == "x-->a-->nullptr");
}
// DList test cases
//insert functions
DList *dl = new DList();
TEST_CASE("DList: Insert function"){
    dl->insert(0,"c");
    CHECK(dl->toString() == "head-->c<--tail");
    dl->insert(1,"d");
    CHECK(dl->toString() == "head-->c<-->d<--tail");
    dl->insert(0,"a");
    CHECK(dl->toString() == "head-->a<-->c<-->d<--tail");
    dl->insert(1,"b");
    CHECK(dl->toString() == "head-->a<-->b<-->c<-->d<--tail");
}
TEST_CASE("DList: Insert function - out of bound"){
    dl->insert(-10,"x");
    CHECK(dl->toString() == "head-->a<-->b<-->c<-->d<--tail");
    dl->insert(10,"x");
    CHECK(dl->toString() == "head-->a<-->b<-->c<-->d<--tail");
    dl->insert(-1,"x");
    CHECK(dl->toString() == "head-->a<-->b<-->c<-->d<--tail");
    dl->insert(5,"x");
    CHECK(dl->toString() == "head-->a<-->b<-->c<-->d<--tail");
}

TEST_CASE("DList: Insert function - at the end"){
    dl->insert(4,"e");
    CHECK(dl->toString() == "head-->a<-->b<-->c<-->d<-->e<--tail");
    dl->insert(5,"f");
    CHECK(dl->toString() == "head-->a<-->b<-->c<-->d<-->e<-->f<--tail");
}

TEST_CASE("DList: Insert function - going backward"){
    dl->insert(5,"x");
    CHECK(dl->toString() == "head-->a<-->b<-->c<-->d<-->e<-->x<-->f<--tail");
    dl->insert(6,"x");
    CHECK(dl->toString() == "head-->a<-->b<-->c<-->d<-->e<-->x<-->x<-->f<--tail");
}

//get functions
TEST_CASE("DList: Get function"){
    CHECK(dl->get(3) == "d");
    CHECK(dl->get(5) == "x");
    CHECK(dl->get(2) == "c");
}

TEST_CASE("DList: Get function - out of bounds"){
    CHECK(dl->get(-10) == "location specified is out of bound");
    CHECK(dl->get(10) == "location specified is out of bound");
    CHECK(dl->get(-1) == "location specified is out of bound");
    CHECK(dl->get(8) == "location specified is out of bound");
}

TEST_CASE("DList: Get function - edges"){
    CHECK(dl->get(0) == "a");
    CHECK(dl->get(7) == "f");
}

//remove functions
TEST_CASE("DList: Removing function"){
    dl->remove(0);
    CHECK(dl->toString() == "head-->b<-->c<-->d<-->e<-->x<-->x<-->f<--tail");
    dl->remove(4);
    CHECK(dl->toString() == "head-->b<-->c<-->d<-->e<-->x<-->f<--tail");
    dl->remove(4);
    CHECK(dl->toString() == "head-->b<-->c<-->d<-->e<-->f<--tail");
}

TEST_CASE("DList: Removing function - out of bound"){
    dl->remove(-10);
    CHECK(dl->toString() == "head-->b<-->c<-->d<-->e<-->f<--tail");
    dl->remove(10);
    CHECK(dl->toString() == "head-->b<-->c<-->d<-->e<-->f<--tail");
    dl->remove(-1);
    CHECK(dl->toString() == "head-->b<-->c<-->d<-->e<-->f<--tail");
    dl->remove(5);
    CHECK(dl->toString() == "head-->b<-->c<-->d<-->e<-->f<--tail");
}

TEST_CASE("DList: Removing function - going backwards"){
    dl->remove(3);
    CHECK(dl->toString() == "head-->b<-->c<-->d<-->f<--tail");
    dl->remove(2);
    CHECK(dl->toString() == "head-->b<-->c<-->f<--tail");
}