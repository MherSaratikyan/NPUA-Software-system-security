#include "RLE2Machine.h"
#include <string>

std::string RLE2Machine::encode(const std::string& txt) const{
    std::string res;
    int len = txt.size();
    int i = 0;
    while((i < len - 1)){
        unsigned int start = i;
        bool repetitive = false;
        if((i < len - 1) && (txt[i + 1] == txt[start])){
            repetitive = true;
            while((i < len) && (txt[i] == txt[start])){
                ++i;
            }
        }else{
            if((i < len - 1) && (txt[i + 1] != txt[i])){
                while((i < len - 1) && (txt[i] != txt[i + 1])){
                    ++i;
                }

            }
        }

        unsigned int count = i - start;
        if(repetitive){
            
            count = count | 0x80;
            unsigned char c = count;
            res += c;
            res += txt[start];
        }else{
            res += static_cast<unsigned char>(count);
            for(int j = start;j < i;++j){
                res += static_cast<unsigned char>(txt[j]);
            }
        }
    }

    return res;
}

std::string RLE2Machine::decode(const std::string& compressed) const {
    std::string decompressed;
    int len = compressed.size();
    int i = 0;
    while(i < len){
        unsigned int count = static_cast<unsigned char>(compressed[i]);
        unsigned char c = compressed[i + 1];
        bool repetitive = count & 0x80;
        if(repetitive){
            count = count ^ 0x80;
            for(int j = 0;j < count;++j){
                decompressed += c;
            }
            

            i += 2;
        }else{
            for(int j = 0;j < count;++j){
                decompressed += compressed[i+1];
                ++i;
            }
            i++;
        }
    }

    return decompressed;
}