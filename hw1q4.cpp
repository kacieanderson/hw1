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

    file >> numberOfLines;
    string lines[numberOfLines];
    int numWords[numberOfLines];

    getline(file, line); 

    for (int k = 0; k < numberOfLines; k++){
      getline(file, line);
      lines[k] = line;
    }

    for (int i = 0; i < numberOfLines; i++){
      stringstream stream(lines[i]);
      string word;
      while(stream >> word){
        ++numberOfWords;
      }
      numWords[i] = numberOfWords;
      numberOfWords = 0;
    }

    for (int c = numberOfLines - 1; c >= 0; c--){
      cout << numWords[c] << endl;
    }

    return 0;
}
