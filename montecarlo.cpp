#include"montecarlo.hpp"

using namespace std;

void MC::fileHandle(string fileName){
    std::ifstream inFile;
    inFile.open(fileName);
    if(!inFile.is_open()){
        cout << "Could not open the file: " << fileName << endl;
    }else{
        while(!inFile.eof()){
            inFile >> totBatches;
            inFile >> totItems;
            inFile >> percentBadBatch;
            inFile >> percentBadItem;
            inFile >>sampledItems;
        }
    }
    inFile.close();
}
void MC::generateDataSets(){
    int rand;
    int countBadItem = 0;
    int countBadBatch = 0; //track current num of bad batches processed
    int maxCountBadBatch = percentBadBatch/totBatches; //num of bad batches per individual dataset

    ofstream outFile;
    
    cout << "Generating Data Sets: " << endl;
    for(int i = 0; i < totBatches; i++){
        //create a file for each batch with n items 
        //each file will contain 'g' or 'b' per item
        //

        if(countBadBatch != maxCountBadBatch){//there are more bad batches till max num of bad batches reached

            ++countBadBatch;
        }else{//they are good batches 

        }

        //rand = rand()%100;

    }
}