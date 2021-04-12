/***************************************************************
  Student Name: Odalys Rodriguez
  File Name: simulation.cpp
  Project 4
***************************************************************/  
#include"simulation.hpp"
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

void Simulation::fileHandling(){
    ifstream inFile;
    inFile.open("readings.txt");
    if(!inFile.is_open()){
        cout << "Could not open the file" << endl;
    }else{
        int days;

        string range;
        int perc;
        int rangeA, rangeB;
        inFile >> days;
        inFile >> categories;
        for(int i = 0; i < categories; i++){
            inFile >> range >> perc;
            this->probabilities.push_back(perc);
            range.erase(range.end()-1);
            range.replace(range.begin(),range.end(),"-"," ");
            stringstream ss;
            ss << range;
            ss >> rangeA >> rangeB;
            if(i == 0){
                rangeVals.push_back(rangeA);
            }
            rangeVals.push_back(rangeB);
        }
        string units;
        inFile >> units;
    }
}
