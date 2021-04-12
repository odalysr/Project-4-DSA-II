
/***************************************************************
  Student Name: Odalys Rodriguez
  File Name: simulation.hpp
  Project 4
***************************************************************/  
#ifndef SIMULATION_HPP
#define SIMULATION_HPP
#include<iostream>
#include<vector>

class Simulation{
    private:
            //int simulatedDays;
            int categories;
            //int numDays;
            std::vector<int> rangeVals;
            std::vector<int> probabilities;
            
    public:
        void fileHandling();
        void analyticalModel();
};
#endif
