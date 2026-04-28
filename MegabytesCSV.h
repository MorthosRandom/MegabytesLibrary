#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <unordered_map>
#include "MegabytesLinkedLists.cpp"



#ifndef MEGABYTESCSV
#define MEGABYTESCSV

#define HEADER 0

//Code? bad.
//Purpose? ego.
//Objective? none.

void DebugPrintCSV();


class Cell{
public:
    std::string contents;
    Cell(){
        contents = std::string();
    }
    void operator=(std::string value){
        contents = value;
    }
    bool operator==(std::string value){
        return contents == value;
    }
};





class CSVSheet{
public:
    int width;

    std::vector<std::vector<std::string>*>* sheet;  
    int rowCursor = 0;
    std::unordered_map<std::string, int>* map;
    ~CSVSheet(){
        delete map;
        delete sheet;
        map = nullptr;
        sheet = nullptr;
    }

    CSVSheet() {
        sheet = new std::vector<std::vector<std::string>*>();
        std::cout << "blank csv sheet created" << std::endl;
    }
    CSVSheet(std::string filename){
        map = new std::unordered_map<std::string, int>();
        std::ifstream ifstream = std::ifstream(filename);
        sheet = new std::vector<std::vector<std::string>*>();
        char cstring[256];
        while(!ifstream.eof()){
        
            ifstream.getline(cstring, sizeof(cstring)); //getline takes a pointer, but arrays decay to pointers implicitly.

            std::vector<std::string>* row = new std::vector<std::string>();

            std::string line = cstring;
            std::regex regex("\"(.*?)\"");
            for(std::smatch sm; std::regex_search(line,sm,regex);){
                row->push_back(sm[1].str());
                line = sm.suffix();

            }
            sheet->push_back(row);
        }
        ifstream.close();
        rowCursor = 0;

        for(int i = 0; i < sheet->at(0)->size(); i++){
            map->insert({sheet->at(HEADER)->at(i), i});
        }

    }

    std::string operator[](std::string str){
        return sheet->at(rowCursor)->at(map->at(str));
        
    }



    void next(){
        rowCursor+=1;
        if(rowCursor > sheet->size()){
            rowCursor = 0;
        }
    }
    void printRow(int num){
        std::vector<std::string>* row = sheet->at(num);

        for(int i = 0; i < row->size(); i++){
            std::cout << row->at(i) << ", ";
        }

        std::cout << std::endl;
    }

    

    
};


#endif