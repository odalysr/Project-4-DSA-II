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
void MC::printSpec(simulationNum){
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
        outFileName = "ds" + (char)i;
        outFile.open(outFileName)

        //each file will contain 'g' or 'b' per item
        randNum += (rand()%100);//obtain a random num 0-99

        if(i%randNum<percentBadBatch){//yield to bad batches
            for(int j = 0; j < toItems; j++){//items per bacth
                if(j%randNum < percentBadItem){//yield to bad items
                    outFile << 'b' << endl;
                }else{//good item
                    outFile << 'g' << endl;
                }
            }
        }else{//good batches
            for(int k = 0; k < toItems; k++){//items per batch
                outFile << 'g' << endl; //all items are good
            }
        }
        outFile.close();
    }
}
void MC::analyzingDataSet(){ //analyze with the number of sampled items
    //sampledItems

    cout << "Analyzing Data Sets: " << endl;


}