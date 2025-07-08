#include<iostream>
#include<fstream>
#include<string>

void write() {
    // std::ios::out -> out refers to write mode (ios_base class contains the ios class)
    std::fstream file("files/write.txt", std::ios::out);

    if(!file.is_open()) {
        std::cerr << "Could'nt open the file\n";
        return;
    }

    // write samplw data
    file << "Hey this is the 1st line" << std::endl
         << "This is 2nd line" << std::endl
         <<  "OFCOURSE, The 3rd line!";

}

void read() {
    std::fstream file("files/read.txt", std::ios::in);
    
    if(!file.is_open()) {
        std::cerr << "Could'nt open the file";
    }

    std::string line;
    while(std::getline(file, line)) {
        std::cout << line << std::endl;
    }
}

// file systems are not copyable, so we pass by reference
void readFile(std::fstream& file) {
    std::string line;
    while(std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

void truncate() {
    // can't use truncate itself, should use out (telling that after truncation )
    std::fstream file("truncated.txt", std::ios::out | std::ios::trunc);

    if(!file.is_open()) {
        std::cerr << "Could'nt open the file!";
        return;
    }
    // after concatination
    readFile(file);

    // we can write if needed
}

void append() {
    // app behaves like out, but out truncates the content, append won't
    std::fstream file("append.txt", std::ios::out | std::ios::in | std::ios::app);
    
    if(!file.is_open()) {
        std::cerr << "Could'nt open the file!";
        return;
    }

    std::cout << "The file content before appending ";
    readFile(file);

    for(int i = 9;i <= 26;i++) {
        file << i;
    }

    std::cout << "The file content after appending ";
    readFile(file);

}


int main() {
    // 1. WRITE MODE
    // write();

    // 2.READ MODE
    // read();

    // 3. APPEND
    // append()
}