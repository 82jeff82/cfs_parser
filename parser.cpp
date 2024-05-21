#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

int main (int argc, char *argv[]) {
    //Unordered word map that contains all of the words and their indices
    std::unordered_map<string, vector<int> > wordMap;    
    char c;                 //Current letter in file
    string tempWord;        //Current word
    int fileIndex = 0;      //Index of character in file
    int wordStartIndex = 0; //Index of start of current word

    //Check to make sure that only a file name is inputted
    if (argc != 2){
        std::cout << "Error:  Invalid number of input arguments" << std::endl;
        return 0;
    }

    //Try opening the file with the given name
    ifstream file(argv[1]);

    if (file.is_open())
    {
        //File has been opened successfully, go through it character by 
        //character 
        while (file.get(c)){
            //Check if the character is not whitespace 
            if (!isspace(c)){
                if (tempWord.empty()){
                    wordStartIndex = fileIndex;
                }
                //Add the current character to the current word
                tempWord+=c;
            }
            else {
                //If the current word is not empty, add it to the map
                if (!tempWord.empty()){
                    //Add the index to the vector of indexes
                    wordMap[tempWord].push_back(wordStartIndex);
                    //Reset tempWord string
                    tempWord.clear();
                }
            }

            //Increment the file index to keep track of the first index of the word
            fileIndex++;
        }
        

        //Handle the edge case where there is a word at the end without a 
        //character after it
        if (!tempWord.empty()){
            wordMap[tempWord].push_back(wordStartIndex);
        }

        file.close();
    }

    else {
        //Error condition
        std::cout << "Unable to open file" << std::endl;
        return 0;
    }

    //Enter the unordered word map into an ordered word map that will 
    //lexicograpically sort the keys
    std::map<string, vector<int> > sortedWordMap(wordMap.begin(), wordMap.end());

    //Print out all of the values in the sorted word map
    for (auto& i: sortedWordMap)
    {
        cout<<i.first<<": ";
        for (auto& j: i.second){
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}