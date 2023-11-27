#ifndef RLE2_H
#define RLE2_H
#include "CipherMachine.h"
#include <string>

class RLE2Machine : public CipherMachine{

    virtual std::string encode(const std::string& ) const override;
    virtual std::string decode(const std::string& ) const override;
};
#endif