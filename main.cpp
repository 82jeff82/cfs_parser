// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (int argc, char *argv[]) {

    //Check to make sure that only a file name is inputted
    if (argc != 2){
        std::cout << "Error:  Invalid number of input arguments" << std::endl;
        return 0;
    }

    string line;
    ifstream myfile(argv[1]);

    std::cout << "File name: " << argv[1] << std::endl;

    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            cout << line << '\n';
        }        
        myfile.close();
    }

  else cout << "Unable to open file"; 

  return 0;
}