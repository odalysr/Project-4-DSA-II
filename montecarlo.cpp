/***************************************************************
  Student Name: Odalys Rodriguez
  File Name: montecarlo.cpp
  Project 4
***************************************************************/  
#include"montecarlo.hpp"
#include<iostream>
#include<string>
#include <bits/stdc++.h>
#include<fstream>

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
                        ++countBadItem;
                }else{//good item
                    outFile << 'g' << endl;
                }
            }
            ++generateDataSetsBadBatches; //count all bad batches
             cout << "Create bad set batch # " << i; //index of bad batch
        }else{//good batches
            for(int k = 0; k < totItems; k++){//items per batch
                outFile << 'g' << endl; //all items are good
            }
        }
        outFile.close();

        cout << ", totBad = " << generateDataSetsBadBatches << " total = " << totBatches << "badpct " << percentBadItem << endl;
    }
}
void MC::analyzingDataSets(){ //analyze with the number of sampled items
    //read every batch file and analyze sampled items
    
    string inFileName = "";
    ifstream inFile;
    int randNum;
    char sampleState;
    int countSampledItems;

    int chosenItem = totItems/sampledItems;//useless line in file, skip
    int countIterations;

    cout << "Analyzing Data Sets: " << endl;
    for(int i = 0; i < totBatches; i++){

        inFileName = "ds" + (char)(i+1);
        inFile.open(inFileName); //read each file separately


        while(!inFile.eof()){//read sampledItems n times from each file
            inFile >> sampleState; 
            
            ++countIterations;
            if((countIterations%chosenItem) == 0){ //chosen item
                ++countSampledItems;//keep track how many sampled items you sampled

                if(countSampledItems == sampledItems){//check for max sampled items
                    if(sampleState == 'b'){//check if batch has bad items
                        ++analyzingDataSetsBadBatches;//batch is bad
                        cout << "Batch #" << i <<" is Bad" << endl; //print that batch is bad
                    }
                }else{
                    break; //break because reached max num of sampled items
                }
            }
            //keep useless items
        }
        
        inFile.close();
    }

}
void MC::PrFailure(){
    double DecimalBadItem = (double)percentBadItem/100; //conversion

    double base = 1 - DecimalBadItem;
    int exponent = sampledItems;
    
    double Pr = pow(base, exponent);

    cout << "Base = " << base << "\t" << "exponent = " << exponent << endl;
    cout << "P(Failure to detect bad batch) = " << Pr << endl;
    cout << "Percent of bad batches actually detected = " << (analyzingDataSetsBadBatches/generateDataSetsBadBatches) << endl;
}
