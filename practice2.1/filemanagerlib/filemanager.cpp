#include "filemanager.h"


void writeDataToFile(string filename, string filedata) {
    string file;
    
    ofstream outFile(RESULT_FOLDER_PATH + filename);

    if (outFile.is_open()) {
        if (filedata == "") {
            filedata = generateData();
        }
        outFile << filedata;
        outFile.close();
    } else {
        cerr << "failed to open the file for writing.\n";
    }
}


string readDataFromFile(string filename) {
    string resultString;
    string line;

    ifstream inFile(RESULT_FOLDER_PATH + filename);

    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            resultString += line + "\n";
        }
        resultString.pop_back();
        inFile.close();
    } else {
        cerr << "failed to open the file for reading.\n";
    }

    return resultString;
}


string readUntilEmptyLine() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string resultString;
    string line;

    while (getline(cin, line) && !line.empty()) {
        resultString += line + "\n";
    }
    resultString.pop_back();

    if (!cin.eof() && cin.fail()) {
        cerr << "an input error has occurred." << endl;
    }

    return resultString;
}


string generateData() {
    string resultString = "";
    string line = "";

    size_t min_countOfLines = 5;
    size_t max_countOfLines = 20;
    size_t countOfLines = min_countOfLines + rand()
                        % (max_countOfLines - min_countOfLines + 1);

    size_t min_countOfCharacters = 1;
    size_t max_countOfCharacters = 10;
    size_t countOfCharacters = 0;

    unsigned int number;
    unsigned int minNumber = 10;
    unsigned int maxNumber = 99;

    for (size_t i = 0; i < countOfLines; ++i) {
        srand(time(NULL) + i);
        countOfCharacters = min_countOfCharacters + rand()
                            % (max_countOfCharacters - min_countOfCharacters + 1);

        for (size_t j = 0; j < countOfCharacters; ++j) {
            number = minNumber + rand() % (maxNumber - minNumber + 1);
            line += to_string(number) + " ";
        }
        line.pop_back();
        resultString += line + "\n";
        line = "";
    }
    resultString.pop_back();

    return resultString;
}


void addNewLineToEndOfFile(string filename, string line) {
    ofstream outFile("text_files/" + filename, ios::app);

    if (outFile.is_open()) {
        outFile << endl << line;
        outFile.close();
    } else {
        cerr << "failed to open the file for additional recording.\n";
    }
}


vector<string> split(string line, char delimiter) {
    vector<string> result;
    istringstream stream(line);
    string characterSequence;

    while (getline(stream, characterSequence, delimiter)) {
        result.push_back(characterSequence);
    }

    return result;
}


vector<string> splitTextFromFile(string filename, char delimiter) {
    string line;
    string text;
    vector<string> characterSequence;

    ifstream inFile(filename);

    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            text += line + delimiter;
        }
        inFile.close();
    } else {
        cerr << "failed to open the file." << filename << endl;
    }

    characterSequence = split(text, ' ');

    return characterSequence;
}


string getNumberBySerialNumber(string filename, unsigned int serialNumber) {
    vector<string> characterSequence = splitTextFromFile(filename, ' ');
    return characterSequence[serialNumber - 1];
}


size_t countNumbersInFile(string filename) {
    vector<string> characterSequence = splitTextFromFile(filename, ' ');
    return characterSequence.size();
}


void matrixFilling(string filename, size_t matrixSize) {
    vector<string> characterSequence = splitTextFromFile(RESULT_FOLDER_PATH + filename, ' ');
    string filedata = "";
    
    unsigned int number;
    unsigned int minNumber = 10;
    unsigned int maxNumber = 99;

    size_t counter = 0;

    srand(time(NULL));

    while (matrixSize*matrixSize > characterSequence.size()) {
        number = minNumber + rand() % (maxNumber - minNumber + 1);
        characterSequence.push_back(to_string(number));
    }

    for (size_t i = 0; i < matrixSize; ++i) {
        do {
            filedata += characterSequence[counter] + ' ';
            counter += 1;
        } while (counter % matrixSize != 0);
        filedata[filedata.size() - 1] = '\n';
    }
    filedata.pop_back();

    writeDataToFile(filename + "_matrix", filedata);
}
