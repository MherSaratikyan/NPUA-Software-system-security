#include <iostream>
#include "SimpleSubstitution.h"
#include "Rows_and_columns.h"
#include "RLEMachine.h"
#include "RLE2Machine.h"
#include "Viginere.h"

int main(){

    //testing simpleSubstitutionMachine
    std::cout<<"\nTesting the simple substitution algo\n";
    SimpleSubstitutionMachine myMachine("National polytechnic University of Armenia");
    std::cout<<myMachine.getAlphabet()<<"\n";
    std::cout<<myMachine.getKey();
    
    std::string text{"Quick brown fox jumps over the lazy dog"};
    std::string result;
    std::cout<<"\n\nPlain text:   "<<text;

    result = myMachine.performOperation(text,CipherMachine::Operation::ENCODE);
    std::cout<<"\nEncoded text: "<<result;

    result = myMachine.performOperation(result,CipherMachine::Operation::DECODE);
    std::cout<<"\nDecoded text: "<<result;

    //testing Rows and Columns cipher machine
    std::cout<<"\nTesting rows and columns algo\n";
    RowsAndColsMachine myMachine2(4);
    std::string txt = "abracadabra";
    std::cout<<"\nThe plain text: "<<txt;
    result = myMachine2.performOperation(txt,CipherMachine::Operation::ENCODE);

    std::cout<<"\nThe cipher text: "<<result;
    result = myMachine2.performOperation(result,CipherMachine::Operation::DECODE);
    std::cout<<"\nAfter decoding the txt: "<<result;

    std::cout<<"\nTesting Rle compressing algorithm:\n";
    std::string init = "ggggggggddddfyuddkkkilhhhhhhhhhhhhhhhoccccccccsewwwwwwwwwww";
    std::cout<<"\nThe initial text: "<<init;
    RLEMachine myMachine3;
    result = myMachine3.performOperation(init,CipherMachine::Operation::ENCODE);
    std::cout<<"\nThe compressed text: "<<result;
    result = myMachine3.performOperation(result,CipherMachine::Operation::DECODE);
    std::cout<<"\nThe decoded text: "<<result;

    std::cout<<"\n\nTesting RLE2 compressing algorithm:\n";
    RLE2Machine myMachine4;
    std::string initial{"aaaaaadbahhhhhhhzdddddmmgggggggssssssswxyzdddooo"};
    std::cout<<"\nInitial string:\n"<<initial;
    std::string compressed = myMachine4.performOperation(initial,CipherMachine::Operation::ENCODE);
    std::cout<<"\nThe compressed string:\n"<<compressed;
    std::string decompressed = myMachine4.performOperation(compressed,CipherMachine::Operation::DECODE);
    std::cout<<"\nThe decompressed string:\n"<<decompressed;
    
    std::cout<<"\n\nTesting Viginere algorithm:\n";
    initial = "Quick brown fox jumps over the lazy dog";
    std::cout<<"\nThe initial text: "<<initial;
    std::string key{"Lemon"};
    std::cout<<"\nThe key: "<<key;
    ViginereMachine myMachine5(key);
    result = myMachine5.performOperation(initial,CipherMachine::Operation::ENCODE);
    std::cout<<"\nThe encoded text: "<<result;
    result = myMachine5.performOperation(result,CipherMachine::Operation::DECODE);
    std::cout<<"\nThe decoded text: "<<result;
}
