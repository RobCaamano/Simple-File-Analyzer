// Roberto Caamano
// Recitation Assignment 3

#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
    string inFile = "";

    // VARS
    string data;
    int numLines = 0;
    int numChars = 0;
    int digits = 0;
    int letters = 0;
    int punct = 0;
    int wordCount = 0;
    int integers = 0;

    // Check command line input
    if(argc > 1){
        inFile = argv[1];
    }
    else{
        cout << "No file is found" << endl;
        return 1;
    }

    // Open file in read mode
    ifstream file_cin;
    file_cin.open(inFile);

    // See if file can be opened
    if(!file_cin){
        cout << "File cannot be opened: " << inFile << endl;
        exit(1);
    }
    
    char current = '\0';
    char last = '\0';
    // Go thru chars in file
    while(file_cin.get(current)){
        // Check if current char is newline
        if(current == '\n' || (current == '\f' && current == '\r')){
            ++numLines;
            ++numChars;
        }
        else{
            numChars++;
        }

        // Integer Check
        if(last != ' ' && isdigit(last) && !(isdigit(current))){
            integers++;
        }
        // Check for words
        if((current == ' ' || current == '\n') && last != ' ' )
            wordCount++;
        last = current;
        
        

        //Check if digit
        if(isdigit(current))
            digits++;

        //Check if letter
        if(isalpha(current))
            letters++;

        //Check if puncutation
        if(ispunct(current))
            punct++;
      
    }

    if(numChars > 0){
        if(isalnum(last))
            wordCount++;
    }

    // Close file
    file_cin.close();

    // Check if empty
    if(numLines == 0){
        cout << "File is empty." << endl;
        exit(0);
    }
    
    // Show results

    cout << "LINES: " << numLines << endl;
    cout << "CHARS: " << numChars << endl;
    cout << "DIGITS: " << digits << endl;
    cout << "LETTERS: " << letters <<endl;
    cout << "PUNCTUATIONS: " << punct << endl;
    cout << "WORDS: " << wordCount << endl;
    cout << "INTEGERS: " << integers << endl;

    return 0;
}
