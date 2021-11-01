#ifndef MERKLETREENODE_H_
#define MERKLETREENODE_H_

#include <string>

class MerkleTreeNode
{
public:
    MerkleTreeNode* left;
    MerkleTreeNode* right;
    MerkleTreeNode* parent;
    std::string hash_value;

    MerkleTreeNode(std::string data);
};

#endif