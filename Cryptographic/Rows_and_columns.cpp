#include "Rows_and_columns.h"
#include <vector>
#include <cmath>
#include <string>

RowsAndColsMachine::RowsAndColsMachine(int key): m_key{key} {}

int RowsAndColsMachine::getKey() const{
    return m_key;
}


std::string RowsAndColsMachine::encode(const std::string& plaintext) const{
    std::string txt{plaintext};
    algorithm(txt,m_key);
    return txt;
}

std::string RowsAndColsMachine::decode(const std::string& ciphertext) const{
    std::string txt{ciphertext};
    algorithm(txt,ceil(static_cast<double>(ciphertext.length())/m_key));
    return txt;
}


void RowsAndColsMachine::algorithm(std::string& plaintext, int key) const{
    
    
    int len = plaintext.length();
    int rows = key;
    int cols = ceil(static_cast<double>(len) / rows);
    
    //generating matrix
    std::vector<std::vector<char>> matrix(key);

    
    int c = 0;
    //writing the plaintext in the matrix
    for(int i{0};i < rows;++i){
        for(int j{0};j < cols;++j){
            if(c < len){
                matrix[i].push_back(plaintext[c]);
                ++c;
            }else{
                matrix[i].push_back(' ');
            }
        }
    }

    c = 0;
    for(int i{0};i < cols;++i){
        for(int j{0};j < rows;++j){
            if(c < len){
                plaintext[c] = matrix[j][i];
                ++c;
            }
        }
    }
}