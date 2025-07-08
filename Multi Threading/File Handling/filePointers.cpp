#include<iostream>
#include<string>
#include<fstream>

/*
    theese pointers will be stored in std::basic_streambuf object usually usually std::filebuf for files
*/

void readFile(std::fstream& file) {
    std::string line;
    while(std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

void tellG() {

    /*
        The get pointer gets the next executable line in a file 
        present in ifstream & fstream
    */

    std::fstream file("files/read.txt", std::ios::in);

    if(!file.is_open()) {
        std::cerr << "Could'nt open the file!";
        return;
    }

    readFile(file);

    std::cout << std::endl << "tellg " << file.tellg(); 
}   

int main() {
    // Get Pointers - tellg, seekg
    tellG();
}