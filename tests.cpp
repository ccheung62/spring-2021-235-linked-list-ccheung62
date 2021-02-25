#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "List.h"

List *l = new List();

//insert function
TEST_CASE("Insert function"){
    l->insert(0,"b");
    CHECK(l->toString() == "b-->nullptr");
    l->insert(1,"c");
    CHECK(l->toString() == "b-->c-->nullptr");
    l->insert(0,"a");
    CHECK(l->toString() == "a-->b-->c-->nullptr");
}

TEST_CASE("Insert function - out of bounds"){
    l->insert(10, "x");
    CHECK(l->toString() == "a-->b-->c-->nullptr");
    l->insert(-10, "x");
    CHECK(l->toString() == "a-->b-->c-->nullptr");
    l->insert(-1, "x");
    CHECK(l->toString() == "a-->b-->c-->nullptr");
    l->insert(4, "x");
    CHECK(l->toString() == "a-->b-->c-->nullptr");
}

TEST_CASE ("Insert function - at the end"){
    l->insert(3, "d");
    CHECK(l->toString() == "a-->b-->c-->d-->nullptr");
    l->insert(4,"e");
    CHECK(l->toString() == "a-->b-->c-->d-->e-->nullptr");
    l->insert(5,"f");
    CHECK(l->toString() == "a-->b-->c-->d-->e-->f-->nullptr");
}

//get function
TEST_CASE("Get function"){
    CHECK(l->get(2) == "c");
    CHECK(l->get(0) == "a");
    CHECK(l->get(5) == "f");
}

TEST_CASE("Get function - out of bounds"){
    CHECK(l->get(6) == "location specified is out of bound");
    CHECK(l->get(-1) == "location specified is out of bound");
    CHECK(l->get(-10) == "location specified is out of bound");
    CHECK(l->get(10) == "location specified is out of bound");
}

//remove function
TEST_CASE ("Remove function"){
    l->remove(0);
    CHECK(l->toString() == "b-->c-->d-->e-->f-->nullptr");
    l->remove(1);
    CHECK(l->toString() == "b-->d-->e-->f-->nullptr");
    l->remove(3);
    CHECK(l->toString() == "b-->d-->e-->nullptr");
}

TEST_CASE("Remove function - out of bound"){
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
TEST_CASE ("Remove function - No Nodes"){
    le->remove(0);
    CHECK(le->toString() == "nullptr");
    le->remove(1);
    CHECK(le->toString() == "nullptr");
    le->remove(2);
    CHECK(le->toString() == "nullptr");
}

TEST_CASE("Insert function - No Nodes"){
    le->insert(2, "x");
    CHECK(le->toString() == "nullptr");
    le->insert(1, "x");
    CHECK(le->toString() == "nullptr");
    le->insert(0, "x");
    CHECK(le->toString() == "x-->nullptr");
}

TEST_CASE("Remove function - One Node"){
    le->remove(2);
    CHECK(le->toString() == "x-->nullptr");
    le->remove(1);
    CHECK(le->toString() == "x-->nullptr");
    le->remove(0);
    CHECK(le->toString() == "nullptr");
}

TEST_CASE("Insert function - One Node"){
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