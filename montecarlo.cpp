#include"montecarlo.hpp"

using namespace std;

void MC::fileHandle(string fileName){
    inFile.open(fileName);
    if(!inFile.is_open()){
        cout << "Could not open the file: " << fileName << endl;
    }else{
        while(!inFile.eof()){
            inFile >> numBatches;
            inFile >> numItems;
            inFile >> percentBadBatch;
            inFile >> percentBadItem;
            inFile >>sampledItems;
        }
    }
    inFile.close();
}
