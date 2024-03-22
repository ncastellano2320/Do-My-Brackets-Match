#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"


// add includes
#include "DSList.h"
using namespace std;

TEST_CASE("Check that DSList works", "[DSList]")
{
    // add test cases (create lists and specify what the expected output is)
    SECTION("Testing Default Constructor", "Check that a Empty List is created using default constructor")
    {
        //This Test Creates an Empty List Using the default constructor
        DSList<int> List;
        REQUIRE(List.size() == 0);  //Should pass because list is empty
    }

    SECTION("Testing Copy Constructor", "checking if copy constructor works correctly")
    {
        //1.Testing Copy Constructor
        DSList<int> list1;
        list1.push_back(1);
        list1.push_back(2);
        list1.push_back(3); //list1 should now contain 1, 2, 3

        DSList<int> copy = DSList(list1); //makes a copy of list1
        REQUIRE(copy.size() == 3); //Should pass because list size before copy is 3 so copy should be too.
    }

    SECTION("Testing Copy Assigment Operator", "checking copy assigment operator")
    {
        //2.Testing Copy Assigment Operator
        DSList<int> list2;
        list2.push_back(1);
        list2.push_back(2); //list1 should now contain 1, 2

        DSList<int> other;
        other.push_back(5);
        other.push_back(6);
        other.push_back(7);

        other = list2;  //other should now have size of 2 instead of 3
        REQUIRE(other.size() == 2);

    }

    SECTION("Testing Size Function")
    {
        DSList<string> words;
        words.push_back("Hi");
        words.push_back("how");
        words.push_back("are");
        words.push_back("you");

        size_t size = words.size();
        REQUIRE(size == 4); //size should be 4 since list has 4 object nodes

    }

    SECTION("Testing is_empty Function", "is the list empty?")
    {

        //Checking filled list
        DSList<double> double_list;
        double_list.push_back(4.4);
        bool check = double_list.is_empty();  //Should return false
        REQUIRE(check == false);

        //Checking empty list
        DSList<int> int_list;
        bool check2 = int_list.is_empty();  //Should return true
        REQUIRE(check2 == true);

    }

    SECTION("Testing empty Function", "clear the whole list")
    {
        DSList<int> L;
        L.push_back(5);
        L.push_back(100);

        //Clear the list
        L.empty();
        REQUIRE(L.size() == 0);  //L list should now be of size 0 since empty

    }

    SECTION("Testing find Function", "find an element with a specific value (and return the position. First element in list is pos 0). Not found returns -1")
    {
        DSList<int> randomList;
        randomList.push_back(18);    //At position 0
        randomList.push_back(982);   //At position 1
        randomList.push_back(8793);  //At position 2
        randomList.push_back(7);     //At position 3

        int position_of_982 = randomList.find(982);  //Should be 1 since it is in position 1
        REQUIRE(position_of_982 == 1);

        int position_of_20 = randomList.find(20);  //Should return -1 since 20 is not in list
        REQUIRE(position_of_20 == -1);

    }

    SECTION("Testing push_front Function", "insert at the beginning of the list (push_front)")
    {
        DSList<int> aList;
        aList.push_front(3);  //Ends up in position 2
        aList.push_front(2);  //Ends up in position 1
        aList.push_front(1);  //Ends up in position 0

        int position_of_3 = aList.find(3);  //Should return the position of 2
        REQUIRE(position_of_3 == 2);

    }

    SECTION("Testing push_back Function", "insert at the end of the list (push_back)")
    {
        DSList<int> List;
        List.push_back(1); //Ends up in position 0
        List.push_back(2); //Ends up in position 1
        List.push_back(3); //Ends up in position 2

        int position_of_3 = List.find(3);  //Should return the position of 2
        REQUIRE(position_of_3 == 2);
    }

    SECTION("Testing pop_front Function", "remove the first element(pop_front)")
    {
        DSList<int> L;
        L.push_back(1); //This element is in the front, position 0
        L.push_back(2); //This element is in the back, when front is popped 2 moves to position 0

        L.pop_front();  //Should get rid of the 1
        int look_for2 = L.find(2);  //2 Should now be in position 0
        REQUIRE(look_for2 == 0);
    }

    SECTION("Testing pop_back Function", "remove the last element (pop_back)")
    {
        DSList<int> L;
        L.push_back(1); //This element is in the front, position 0
        L.push_back(2); //This element is last position 1

        L.pop_back();  //Should get rid of the 2
        int look_for2 = L.find(2);  //Should return -1 since 2 was popped
        REQUIRE(look_for2 == -1);
    }

    SECTION("Testing front Function", "Look at the first element in the Front of the List")
    {
        DSList<int> list;
        list.push_front(10);
        list.push_front(9);
        list.push_front(8); //head pointer should be pointing here

        int first_object = list.front();  //first_object should be 8
        REQUIRE(first_object == 8);

    }

    SECTION("Testing print Function", "Print all the objects in the List")
    {
        //Since all other essential functions work, print should print in correct order
        DSList<int> count_down;
        count_down.push_back(5);
        count_down.push_back(4);
        count_down.push_back(3);
        count_down.push_back(2);
        count_down.push_back(1);

        //count_down list should print 5 -> 4 -> 3 -> 2 -> 1 ->
        count_down.print();

    }

}

// you can run the test using Run CTest in the task bar or by running the tests executable.