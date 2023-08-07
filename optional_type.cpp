#include<iostream>
#include<optional>
#include<fstream>
#include<string>

std::optional<std::string> ReadFileAsString(const std::string& filePath) {
    std::ifstream stream(filePath);
    if (stream) {
        std::string result;
        // read file
        stream.close();
        return result;
    } 
    return {};
}


int main() {
    auto data = ReadFileAsString("data.txt");

    // if data is present then it will have the file content, else it will have the default value 
    std::string value = data.value_or("This is the default value");
    // you can also do if(data)
    if(data.has_value()) {
        std::cout << "File read successfully" << std::endl;
        std::cout << value << std::endl;
    } else {
        std::cout << value << std::endl;
        std::cout << "Not able to read the file" << std::endl;
    }
    
}
