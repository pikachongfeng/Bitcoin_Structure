#ifndef MERKLETREE_H_
#define MERKLETREE_H_

#include <string>
#include <vector>
#include "MerkleTreeNode.h"

std::string _hash_sha256(std::string total);
std::string hash_sha256(std::string a);
std::string hash_sha256(std::string a,std::string b);

class MerkleTree
{
public:
    MerkleTree(std::vector<std::string>& leaves);
    ~MerkleTree();
    void _PrintTree(MerkleTreeNode* node, int indent);
    void PrintTree();
    void deleteTree(MerkleTreeNode* root);

    MerkleTreeNode* root;
};

#endif