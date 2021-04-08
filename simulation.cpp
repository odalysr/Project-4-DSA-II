#include"simulation.hpp"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void Simulation::fileHandling(){
    ifstream inFile;
    inFile.open("readings.txt");
    if(!inFile.is_open()){
        cout << "Could not open the file" << endl;
    }else{
        int days;
        categories;
        while(!inFile.eof()){

        }
    }
}