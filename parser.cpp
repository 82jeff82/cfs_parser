#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

int main (int argc, char *argv[]) {

    //Check to make sure that only a file name is inputted
    if (argc != 2){
        std::cout << "Error:  Invalid number of input arguments" << std::endl;
        return 0;
    }

    ifstream file(argv[1]);
    std::unordered_map<string, vector<int> > wordMap;
    char c;
    string tempWord;
    int fileIndex = 0;
    int wordStartIndex = 0;
    vector<int> tempVector;


    if (file.is_open())
    {
        cout << "Successfully opened file..." << endl;
        while (file.get(c)){
            if (!isspace(c)){
                if (tempWord.empty()){
                    wordStartIndex = fileIndex;
                }
                tempWord+=c;
                
            }
            else {
                if (!tempWord.empty()){
                    wordMap[tempWord].push_back(wordStartIndex);
                    wordStartIndex = -1;
                    //Reset tempWord string and the character index to be 0
                    tempWord.clear();
                }
            }

            //Increment the file index to keep track of the first index of the word
            fileIndex++;
        }
        

        //Handle the edge case where there is a word at the end without a character after it
        if (!tempWord.empty()){
            wordMap[tempWord].push_back(wordStartIndex);
        }

        file.close();
    }

    else {
        std::cout << "Unable to open file" << std::endl;
        return 0;
    } 

    //Print out the entire map with each index
    for (auto& i: wordMap)
    {
        cout<<i.first<<": ";
        for (auto& j: i.second){
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
     
    std::map<string, vector<int>> sortedWordMap(wordMap.begin(), wordMap.end());
    
    std::cout << "Ordered map:" << std::endl;

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