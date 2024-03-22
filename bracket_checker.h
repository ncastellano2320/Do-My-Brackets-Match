
#ifndef ASSIGNMENT3_BRACKETS_BRACKET_CHECKER_H
#define ASSIGNMENT3_BRACKETS_BRACKET_CHECKER_H

using namespace std;
#include <fstream>
#include <string>
#include "DSStack.h"
#include "DSStack_Vector.h"

class bracket_checker {
private:
    DSStack_Vector<char> vector_stack; //Stack with array
    DSStack<char> linked_stack;  //Stack with list
public:
    int read_check_with_linked_stack(const string& the_file) {
        ifstream file(the_file);

        // Check if file is open
        if (!file.is_open()) {
            cerr << "Error: file not found" << endl;
            return -1;
        }

        //read through each line
        string line;
        int error = 0;
        int line_count = 1;
        while(getline(file,line)) {
            for (int i = 0; i < (int)line.length(); i++) {

                if (linked_stack.is_empty() && is_closeBracket(line[i])) {
                    error = 1;
                    cout << "Error: Close Bracket by itself here on " << line_count << " " << line[i] << endl;
                    continue;
                }

                if (is_openBracket(line[i])) {
                    linked_stack.push(line[i]);
                }

                if (is_closeBracket(line[i])) {
                    if (bracket_type_check(line[i],linked_stack.peek())) {
                        linked_stack.pop();
                    } else {
                        error = 1;
                        cout << "Error: Bracket Mismatch here on " << line_count;
                        cout << " Missing open for: " << line[i] << std::endl;
                    }
                }

            }

            line_count++;
        }

        if (!linked_stack.is_empty()) {
            error = 1;

        }

        //Close file
        file.close();

        //clear the stack
        linked_stack.clear();

        return error;
    }

    int read_check_with_array_stack(const string& the_file) {
        ifstream file(the_file);

        // Check if file is open
        if (!file.is_open()) {
            cerr << "Error: file not found" << endl;
            return -1;
        }

        string line;
        int error = 0;
        int line_count = 1;
        while(getline(file,line)) {
            for (int i = 0; i < (int)line.length(); i++) {
                if (vector_stack.is_empty() && is_closeBracket(line[i])) {
                    error = 1;
                    cout << "Error: Close Bracket by itself here on " << line_count << " " << line[i] << endl;
                    continue;
                }

                if (is_openBracket(line[i])) {
                    vector_stack.push(line[i]);
                }

                if (is_closeBracket(line[i])) {
                    if (bracket_type_check(line[i],vector_stack.peek())) {
                        vector_stack.pop();
                    } else {
                        error = 1;
                        cout << "Error: Bracket Mismatch here on " << line_count;
                        cout << " Missing open for: " << line[i] << std::endl;
                    }
                }

            }

            line_count++;
        }

        if (!vector_stack.is_empty()) {
            error = 1;
        }

        //Close file
        file.close();

        //clear the stack
        vector_stack.clear();

        return error;

    }


    static bool is_openBracket(char& x) {
        if (x == '(' || x == '{' || x == '[') {
            return true;
        }
        return false;
    }

    static bool is_closeBracket(char& x) {
        if (x == ')' || x == '}' || x == ']') {
            return true;
        }
        return false;
    }

    static bool bracket_type_check(char& x, char top_of_Stack) {
        if (x == ']') {
            if (top_of_Stack == '[') {
                return true;
            }
        } else if (x == '}') {
            if (top_of_Stack == '{') {
                return true;
            }
        } else if (x == ')') {
            if (top_of_Stack == '(') {
                return true;
            }
        }

        return false;
    }


};

#endif //ASSIGNMENT3_BRACKETS_BRACKET_CHECKER_H
