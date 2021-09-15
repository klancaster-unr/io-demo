#include <iostream>
#include <fstream>


void resetStream(std::ifstream &dataFile);

void readDemo();

void outputDemo();

int main() {
    readDemo();
    outputDemo();
    return 0;
}

void outputDemo() {
    std::ofstream outputFile("output.txt");
    if(!outputFile.fail()){ // or you could use fail()
        std::cout << "Could not create file" << std::endl;
        exit(1);
    }
    outputFile << "Some text and a number kjhlkjhkjhkjh" << 12 << std::endl;
    outputFile << "Another line and a number " << 12 << std::endl;
    outputFile.close();
}

void readDemo() {
    std::string inputFile = "myfile.txt";
    std::ifstream dataFile(inputFile);
    if(dataFile.fail()){
        std::cout << "Could not find file" << std::endl;
        exit(1);
    }
    // read a word at a time
    std::string word;
    while(dataFile >> word){
        std::cout <<  word << std::endl;
    }
    resetStream(dataFile);
    std::string line;
    std::string fname, lname, role;
    int age;
    while(std::getline(dataFile,line)){
        std::cout << line << std::endl;
        // now we have to split the string to get the values
    }
    resetStream(dataFile);
    while(dataFile >> lname,dataFile >> fname, dataFile >> role, dataFile >> age){
        std::cout << "lname : " << lname << std::endl;
        std::cout << "fname : " << fname << std::endl;
        std::cout << "role  : " << role  << std::endl;
        std::cout << "age   : " << age   << std::endl;
    }
    dataFile.close();
}

void resetStream(std::ifstream &dataFile) {
    dataFile.clear();
    dataFile.seekg(std::ios::beg);
}
