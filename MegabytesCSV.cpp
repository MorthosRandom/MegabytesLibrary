#include "MegabytesCSV.h"
#include <iostream>
#include <fstream>
#include <vector>
//the fact that I apparently need to include both of these is some bullshit



class CsvReader{
public:
    std::vector<std::vector<std::string>>* sheet;
    CsvReader() {
        std::cout << "blank csv reader created" << std::endl;
    }
    CsvReader(std::string filename){
        //sheet = 
    }
};


//https://www.youtube.com/watch?v=fhzKLBZJC3w&list=RDfhzKLBZJC3w&start_radio=1&pp=oAcB

void DebugPrintCSV(){
    std::ifstream* ifstream = new std::ifstream();
    ifstream->open(R"(C:\Users\escop\Downloads\Safety_Dashboard_ODYS_DDT6_2026-04-12.csv)");

    char cstring[256];
    
    while(!ifstream->eof()){
        
        ifstream->getline(cstring, sizeof(cstring)); //getline takes a pointer, but arrays decay to pointers implicitly.
        std::cout << cstring << std::endl;
    }
    
    
    ifstream->close();
}