#include <iostream>
#include <algorithm>

#include "DSList.h"
#include "DSStack.h"
#include "DSStack_Vector.h"
#include "bracket_checker.h"
#include <chrono>

using namespace std;

int main(int argc, char **argv)
{
    //Set Timer for Linked List Stack
    auto start = chrono::high_resolution_clock::now();

    bracket_checker checker;
    for (int i = 1; i < argc; ++i) {
        if (checker.read_check_with_linked_stack(argv[i]) == 0) {
            cout << argv[i] << ": OK" << endl << endl;
        } else {
            cout << argv[i] << ": Bracket mismatch detected" << endl << endl;
        }

    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Elapsed time for ListStack: " << elapsed.count() << " seconds\n" << endl;


    //Set Timer for Array Stack
    auto start2 = chrono::high_resolution_clock::now();

    bracket_checker checker2;
    for (int i = 1; i < argc; ++i) {
        if (checker2.read_check_with_array_stack(argv[i]) == 0) {
            cout << argv[i] << ": OK" << endl << endl;
        } else {
            cout << argv[i] << ": Bracket mismatch detected" << endl << endl;
        }

    }

    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed2 = end - start;
    cout << "Elapsed time for Array Stack: " << elapsed2.count() << " seconds\n" << endl;
    // A return code != 0 tells the operating system that there is an issue.
    return 1;
}

// in the terminal type `cd build` and then `./check_brackets test_data/*`