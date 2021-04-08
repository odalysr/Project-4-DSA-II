#include"montecarlo.hpp"
#include<iostream>
#include<string>

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
void MC::printSpecs(int simulationNum){
    cout << "Simulation " << simulationNum << ":" << endl;
    cout << "\t Number of batches of items: " << totBatches << endl;
    cout << "\t Number of items in each batch: " << totItems << endl;
    cout << "\t Percentage of batches containing bad items: " << percentBadBatch << endl;
    cout << "\t Percentage of items that are bad in a bad set: " << percentBadItem << endl;
    cout << "\t Items sampled from each set: " << sampledItems << endl;
}
void MC::generateDataSets(){
    int randNum;
    int countBadItem = 0;
    int countBadBatch = 0; //track current num of bad batches processed
    string outFileName = "";

    ofstream outFile;
    
    cout << "Generating Data Sets: " << endl;

    for(int i = 0; i < totBatches; i++){
        //create a file for each batch with n items 
        outFileName = "ds" + (char)(i+1);
        outFile.open(outFileName);

        //each file will contain 'g' or 'b' per item
        randNum = (rand()%100);//obtain a random num 0-99

        if(i%randNum<percentBadBatch){//yield to bad batches
            for(int j = 0; j < totItems; j++){//items per bacth
                if(j%randNum < percentBadItem){//yield to bad items
                    outFile << 'b' << endl;
                }else{//good item
                    outFile << 'g' << endl;
                }
            }
        }else{//good batches
            for(int k = 0; k < totItems; k++){//items per batch
                outFile << 'g' << endl; //all items are good
            }
        }
        outFile.close();
    }
}
void MC::analyzingDataSets(){ //analyze with the number of sampled items
    //read every batch file and analyze sampled items
    
    string inFileName = "";
    ifstream inFile;
    int countSampledItems = 0;
    int randNum;

    cout << "Analyzing Data Sets: " << endl;
    for(int i = 0; i < totBatches; i++){

        inFileName = "ds" + (char)(i+1);
        inFile.open(inFileName);

        while(!inFile.eof()){//read random lines n time from each file
            
        }
        
        inFile.close();
    }

}
void PrFailure(){
    
}