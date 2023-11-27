#include "CipherMachine.h"
#include <string>

 std::string CipherMachine::performOperation(const std::string& text,CipherMachine::Operation op){
    if(op == CipherMachine::Operation::ENCODE){
        return encode(text);
    }else{
        return decode(text);
    }
}