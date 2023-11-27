#ifndef MACHINE_H
#define MACHINE_H

#include <string>
class CipherMachine{
public:
    enum class Operation{ENCODE,DECODE};
    std::string performOperation(const std::string&, CipherMachine::Operation);
private:
    virtual std::string encode(const std::string& ) const = 0;
    virtual std::string decode(const std::string& ) const = 0;
};
#endif