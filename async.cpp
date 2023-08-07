#include<iostream>
#include<vector>
#include<future>
#include<fstream>


void load_file(std::string file) {
    std::ofstream myfile;
    myfile.open(file);
    myfile << "Writing to the file";
    myfile.close();
    return;

};

int main() {
    std::vector<std::future<void>> tasks;
    std::vector<std::string> files = {
        "hello.txt",
        "hello1.txt",
        "hello2.txt",
        "hello3.txt",
        "hello4.txt",
        "hello5.txt",
        "hello6.txt",
        "hello7.txt",
        "hello8.txt"
    };
    for(auto file: files) {
        tasks.push_back(std::async(std::launch::async, load_file, file));
    }

}
