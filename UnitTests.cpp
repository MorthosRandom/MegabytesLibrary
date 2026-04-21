
#include <iostream>
#include "MegabytesCSV.h"


int main(){
    CSVSheet csvReader = CSVSheet(R"(C:\Users\escop\Downloads\Safety_Dashboard_ODYS_DDT6_2026-04-12.csv)");
    csvReader.next();
    csvReader.next();
    std::cout << csvReader["Delivery Associate "] << std::endl;

}