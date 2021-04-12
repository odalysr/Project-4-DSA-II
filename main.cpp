/***************************************************************
  Student Name: Odalys Rodriguez
  File Name: main.cpp
  Project 4
***************************************************************/  
#include<vector>
#include<iostream>
#include<sstream>
#include<string>
#include"montecarlo.hpp"
using namespace std;

int main() {
   MC obj;
   //fileNames t1-t4.txt
   string filename;
   
   for(int i = 0 ; i <4 ; i++){
      filename = "ds" + (char)i;
      obj.fileHandle(filename);
      obj.printSpecs(i+1);
      obj.generateDataSets();
      obj.analyzingDataSets();
      cout << endl;
   }

   return 0;
}

