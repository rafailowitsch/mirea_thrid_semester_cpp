#include <iostream>
#include <stdint.h>

#include "filemanagerlib/filemanager.h"

using namespace std;

int main() {
    bool            flag;                // flag responsible for program cycling
    size_t          alternativeNumber;   // number of the function selected by the user
    string  filename;
    string  filedata;
    string line;
    unsigned int number;

    flag = true;

    while (flag) {
        puts("\n"
             " ┌──────────────────file─manager──────────────────┐\n"
             " ├ 1. type text into a file                       │\n"
             " ├ 2. output text from a file                     │\n"
             " ├ 3. add a new line to the end of the file       │\n"
             " ├ 4. get the number by its serial number         │\n"
             " ├ 5. determine the number of numbers in the file │\n"
             " ├ 6. matrix filling                              │\n"
             " ├ 7. exit                                        │\n"
             " └────────────────────────────────────────────────┘\n");

        cout << "select a function and enter its number" << endl << " -> ";
        cin >> alternativeNumber;
        puts("");

        switch(alternativeNumber) {
            case 1:
                cout << "enter a file name: " << endl << " -> ";
                cin >> filename;

                cout << "enter the contents of the file: " << endl;
                filedata = readUntilEmptyLine();
                writeDataToFile(filename, filedata);

                break;

            case 2:
                cout << "enter a file name " << endl << " -> ";
                cin >> filename;
                puts("");

                filedata = readDataFromFile(filename);
                cout << "file data:" << endl;
                cout << filedata << endl;

                break;

            case 3:
                filedata = "";

                cout << "enter a file name " << endl << " -> ";
                cin >> filename;
                cout << "enter a line" << endl << " -> ";
                
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, filedata);
                addNewLineToEndOfFile(filename, filedata);

                break;

            case 4:
                cout << "enter a file name: " << endl << " -> ";
                cin >> filename;
                cout << "enter the sequence number of the number in the file " << endl << " -> ";
                cin >> number;

                printf("the number %d is %s\n", number, getNumberBySerialNumber(filename, number).c_str());

                break;

            case 5:
                cout << "enter a file name " << endl << " -> ";
                cin >> filename;
                cout << countNumbersInFile(filename);

                break;

            case 6:
                cout << "enter a file name " << endl << " -> ";
                cin >> filename;
                cout << "enter the dimension of the matrix" << endl << " -> ";
                cin >> number;

                matrixFilling(filename, number);

                filedata = readDataFromFile(filename + "_matrix");
                cout << "file data:" << endl << filedata << endl;

                break; 

            default:
                flag = false;
                break;
        }
    }

    return 0;
}