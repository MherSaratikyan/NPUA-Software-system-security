#include <iostream>
#include <string>
#include "HuffmanTree.hpp"

int main(){
    HuffmanTree myTree;
    std::string text{"Hello world!"};
    myTree.buildTree(text);
    myTree.printTree();
}