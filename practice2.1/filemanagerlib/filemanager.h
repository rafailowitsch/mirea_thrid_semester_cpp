#ifndef FILE_MANAGER_LIB
#define FILE_MANAGER_LIB

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <time.h>

using namespace std;

#define RESULT_FOLDER_PATH "text_files/"


void            writeDataToFile(string filename, string filedata);
void            addNewLineToEndOfFile(string filename, string line);

string          readDataFromFile(string filename);
string          getNumberBySerialNumber(string filename, unsigned int serialNumber);
string          readUntilEmptyLine();
string          generateData();

size_t          countNumbersInFile(string filename);

vector<string>  split(string line, char delimiter);

void            matrixFilling(string filename, size_t matrixSize);


#endif //FILE_MANAGER_LIB