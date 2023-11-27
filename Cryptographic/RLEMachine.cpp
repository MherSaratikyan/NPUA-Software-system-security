#include "RLEMachine.h"
#include <string>

std::string RLEMachine::encode(const std::string& input) const{
    std::string compressed;
    int length = input.length();
    for (int i = 0; i < length; i++) {
        char currentChar = input[i];
        int count = 1;
        while (i + 1 < length && input[i + 1] == currentChar) {
            count++;
            i++;
        }
        compressed += currentChar;
        compressed += std::to_string(count);
    }
    return compressed;
}

std::string RLEMachine::decode(const std::string& input) const{
    std::string decompressed;
    int length = input.size();
    int i = 0;
    while(i < length){
        char current = input[i];
        ++i;
        int count = 0;
        while(isdigit(input[i])){
            count = 10 * count + (input[i] - '0');
            ++i;
        }

        for(int j = 0;j < count;++j){
            decompressed += current;
        }
    }
    
    return decompressed;
}

