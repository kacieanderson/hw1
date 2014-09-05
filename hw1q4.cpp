#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

int main(int argc, char ** argv){
    ifstream file(argv[1]);
    int numberOfLines = 0;
    int numberOfWords = 0;
    string line;
    string word;

    file >> numberOfLines; // gets the number of lines to check from the 1st line in the file
    string lines[numberOfLines];
    int numWords[numberOfLines];

    getline(file, line); 

    for (int k = 0; k < numberOfLines; k++){
      getline(file, line); 
      lines[k] = line; // fills an array with each individual line in the file
    }

    for (int i = 0; i < numberOfLines; i++){
      stringstream stream(lines[i]); // looks at an individual line
      string word;
      while(stream >> word){ // while the sstream can get another word...
        ++numberOfWords; // ...update the number of words gotten
      }
      numWords[i] = numberOfWords; // fills an array with the number of words in each line
      numberOfWords = 0; 
    }

    for (int c = numberOfLines - 1; c >= 0; c--){
      cout << numWords[c] << endl; // outputs the number of words in each line, backwards.
    }

    return 0;
}
