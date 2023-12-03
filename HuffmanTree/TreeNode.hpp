#ifndef TREENODE_H
#define TREENODE_H

class TreeNode{
public:
    TreeNode(char, int);
    char getSymbol() const;
    int getFrequency() const;
private:
    char m_symbol;
    int m_frequency;
    TreeNode* m_left;
    TreeNode* m_right;

    //responsible for constructing and destroying the huffman tree
    friend class HuffmanTree;
};
#endif