#ifndef MONTECARLO_HPP
#define MONTECARLO_HPP
#include<iostream>
#include<fstream>
#include<string>

class MC{
    private:
        int numBatches;
        int numItems;
        int percentBadBatch;
        int percentBadItem;
        int sampledItems;
        std::ifstream inFile;

    public:
        void fileHandle(std::string fileName); //store those values in data members
        

};
#endif