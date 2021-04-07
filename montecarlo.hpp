#ifndef MONTECARLO_HPP
#define MONTECARLO_HPP
#include<iostream>
#include<fstream>
#include<string>

class MC{
    private:
        int totBatches;//total batches with n items
        int totItems;//items per batch
        int percentBadBatch;
        int percentBadItem;
        int sampledItems;

    public:
        void fileHandle(std::string fileName); //store those values in data members
        void printSpecs(int simulationNum);
        void generateDataSets(); //generate dataset for each file containing specs
        void analyzingDataSets();

};
#endif