#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

// add includes
#include "DSStack.h"
#include "DSStack_Vector.h"
using namespace std;

TEST_CASE("Check that DSStack works", "[DSStack]")
{
    // add test cases (create lists and specify what the expected output is)
    SECTION("Testing Push Function") {
        DSStack<int> stack;
        stack.push(1);
        stack.push(2);
        stack.push(3); //Stack should now contain 3 elements

        REQUIRE(stack.size() == 3);

    }

    SECTION("Testing Pop Function") {
        DSStack<int> stack;
        stack.push(1);
        stack.push(2);
        stack.push(3);  //Last one pushed in

        stack.pop(); //Should pop off the 3
        int top = stack.peek();  //Should equal 2
        REQUIRE(top == 2);
    }

    SECTION("Testing is_empty Function") {
        DSStack<int> stack;  //empty stack
        REQUIRE(stack.is_empty() == true);
    }

    SECTION("Testing peek function") {
        DSStack<int> stack;
        stack.push(5);
        stack.push(4);
        stack.push(9);  //top should be 9

        REQUIRE(stack.peek() == 9);
    }

    SECTION("Testing size function") {
        DSStack<int> stack;
        stack.push(2);
        stack.push(3);  //size of stack should be 2

        REQUIRE(stack.size() == 2);
    }
}

TEST_CASE("Check that DSStack_Vector works", "[DSStack_Vector]")
{
    SECTION("Testing push function") {
        DSStack_Vector<int> stack;
        stack.push(1);
        stack.push(2);
        stack.push(3); //stack should be full

        REQUIRE(stack.is_empty() == false);
    }

    SECTION("Testing pop function") {
        DSStack_Vector<char> stack;
        stack.push(1);
        stack.push(2);

        stack.pop();
        stack.pop();  //now stack should have everything popped off and be empty

        REQUIRE(stack.is_empty() == true);
    }

    SECTION("Testing is_empty function") {
        DSStack_Vector<int> stack; //empty stack
        REQUIRE(stack.is_empty() == true);
    }

    SECTION("Testing peek function") {
        DSStack_Vector<int> stack;
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.pop(); //peek should now be 2;

        REQUIRE(stack.peek() == 2);

    }

}

// you can run the test using Run CTest in the task bar or by running the tests executable. 