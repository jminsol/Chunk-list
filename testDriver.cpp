//
//  main.cpp
//  ChunkList
//
//  Created by JeongMinsol on 2/23/20.
//  Copyright © 2020 Minsol Jeong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Chunk.cpp"
#include "Chunk.hpp"

using namespace std;

int main() {

    string inputFile_name;
    string command;
    ifstream input;
    ChunkList<int> chunk;
    int num;

    cout << "Enter the input file name: ";  //Type Chunkin.txt
    cin >> inputFile_name;
    input.open(inputFile_name);
    
    input >> command;
    
    int numCommands=0;
    while(command != "Quit"){
        if (command == "Append"){
            input >> num;
            chunk.Append(num);
        }
        else if (command == "GetLength")
            cout << "The length is " << chunk.GetLength() << endl;

        else if (command == "GetIndex"){
            input >> num;
            cout << "The value of the index " << num << " is " << chunk.GetIndex(num) <<endl;
        }
        else if (command == "Contains"){
            input >> num;
            cout << "The element " << num;
            if (chunk.Contains(num))
                cout << " is in the chunks" << endl;
            else
                cout << " is not in the chunks" << endl;
        }
        else if (command == "Print"){
            chunk.Print();
        }
        else if (command == "Remove"){
            input >> num;
            chunk.Remove(num);
            cout << "The element " << num << " is deleted." << endl;
        }
        else if (command == "IsEmpty"){
            if (chunk.IsEmpty()){
                cout << "It's empty" << endl;
            }
            else
                cout<< "There is chunks" << endl;
        }
        else{
            cout << "Can't recognize your command: " <<command << " Please check it again" <<endl;
            break;
        }
        numCommands++;
        input >> command;
        cout << " Command number " << numCommands << " completed" <<endl;
    }
    

    input.close();
    return 0;
}
