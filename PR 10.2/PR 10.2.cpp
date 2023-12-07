#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string deleteBetweenBrackets(const string& str) {
    string result = "";
    int openBracketsCount = 0;

    for (char ch : str) {
        if (ch == '(') {
            openBracketsCount++;
        }
        else if (ch == ')' && openBracketsCount > 0) {
            openBracketsCount--;
        }
        else if (openBracketsCount == 0) {
            result += ch;
        }
    }

    return result;
}

void processFile(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (inFile.is_open() && outFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            string processedLine = deleteBetweenBrackets(line);
            outFile << processedLine << endl;
        }
        inFile.close();
        outFile.close();
        cout << "File processing complete." << endl;
    }
    else {
        cout << "Unable to open files." << endl;
    }
}

int main() {
    string inputFileName = "t1.txt"; // Змінити на відповідні імена файлів
    string outputFileName = "t2.txt"; // Змінити на відповідні імена файлів

    processFile(inputFileName, outputFileName);

    return 0;
}

