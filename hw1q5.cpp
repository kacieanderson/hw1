#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

int main(int argc, char ** argv){
    ifstream file(argv[1]);
    int numBuckets = 0;
    int numCommands = 0;
    string line;

    file >> numBuckets;
    file >> numCommands;

    // dynamically allocate an array to contain buckets
    int ** buckets = new int*[numBuckets];

    getline (file, line);
    for (int i = 0; i < numCommands + 1; i++){
      getline(file, line); // look at each individual command
      string command;
      int bucket = 0;
      int numToAdd = 0;
      stringstream stream(line); // look at each word/number in the command
      stream >> command;
      if (command == "PUT"){
        stream >> bucket; // get which bucket to add to
        stream >> numToAdd; // get how many numbers to add
        if (bucket <= numBuckets-1){
          int num = 0;
          while (stream >> num){
            for (int k = 0; k < numToAdd; k++){ // add each individual number
             buckets[bucket][k] = num;
            }
          }
        } else{ // Error handling
          cout << "Error - bucket " << bucket << " does not exist" << endl;
        }
      } else if (command == "EMPTY"){
        stream >> bucket;
        if (bucket <= numBuckets-1){
          buckets[bucket][0] = 0; // empty bucket
        } else{ // Error handling
          cout << "Error - bucket " << bucket << " does not exist" << endl;
        }  
      } else if (command == "OUTPUT"){
        stream >> bucket;
        if (bucket <= numBuckets-1){
          cout << buckets[bucket] << endl; // output bucket
        } else{ // Error handling
          cout << "Error - bucket " << bucket << " does not exist" << endl;
        } 
      }

    }

    delete [] buckets; // deallocate

    return 0;
}
