// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    string line;
    ifstream infile("test.s");
    ofstream outfile ("example.txt");

    if (!infile.is_open())
    {
      cout << "Unable to open file";
      return 0;
    }

    while ( getline (infile,line) )
    {
        cout << line << '\n';
    }
    myfile.close();


}
