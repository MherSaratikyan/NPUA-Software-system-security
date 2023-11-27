#include "Viginere.h"
#include <cstddef>
#include <cctype>


ViginereMachine::ViginereMachine(const std::string& key): m_key{key} {}

std::string ViginereMachine::encode(const std::string& plaintext) const{
    const std::size_t sizeOfAlphabet = 255;
    const std::size_t lenOfText = plaintext.size();
    const std::size_t lenOfKey = m_key.size();

    std::string encoded;
    for(int i{0};i < lenOfText;++i){
        char character = plaintext[i];
        char key_char = m_key[i % lenOfKey];
        unsigned char encrypted_char = ((static_cast<unsigned char>(character) + static_cast<unsigned char>(key_char)) % 255);
        encoded += encrypted_char;
    }
    return encoded;
}


std::string ViginereMachine::decode(const std::string& ciphertext) const{
    const std::size_t sizeOfAlphabet = 255;
    const std::size_t lenOfText = ciphertext.size();
    const std::size_t lenOfKey = m_key.size();

    std::string decoded;
    for(int i{0};i < lenOfText;++i){
         char character = ciphertext[i];
        char key_char = m_key[i % lenOfKey];
        char decrypted_char = (static_cast<unsigned char>(character) - static_cast<unsigned char>(key_char) + 255) % 255;
        decoded += decrypted_char;
    }
    return decoded;
}
