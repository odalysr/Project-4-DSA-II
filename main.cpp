#include<vector>
#include<iostream>
#include<sstream>
using namespace std;

int main() {
   string a_string = "Hello world how are you";
   stringstream ss(a_string);

   vector<string> tokens;
   string temp_str;

   while(getline(ss, temp_str, ' ')){
      tokens.push_back(temp_str);
   }
   for(int i = 0; i < tokens.size(); i++) {
      cout << tokens[i] << endl;
   }
}

//create a class to simulate
/*MC obj;

    obj.fileHandling(t1.txt);

*/