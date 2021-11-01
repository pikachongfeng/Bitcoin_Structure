#include "MerkleTree.h"
#include <memory>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include "SHA256.h"

std::string a_hash_sha256(std::string total)
{
    SHA256 sha;
    sha.update(total);
    uint8_t* digest = sha.digest();
    return SHA256::toString(digest);
}

std::string ahash_sha256(std::string a,std::string b){
    std::string temp =a_hash_sha256(a+b);
    return a_hash_sha256(temp);
}

std::string ahash_sha256(std::string a){
    std::string temp =a_hash_sha256(a+a);
    return a_hash_sha256(temp);}

MerkleTree::MerkleTree(std::vector<std::string>& leaves)
{
    std::vector<MerkleTreeNode*> blocks,nodes;
    for (std::string leave : leaves){
        blocks.push_back(new MerkleTreeNode(ahash_sha256(leave)));
    }
    while (blocks.size() != 1){
        for (int i = 0,n = 0; i < blocks.size(); i += 2, ++n){
            if (i != blocks.size() - 1){
                nodes.push_back(new MerkleTreeNode(ahash_sha256(blocks[i]->hash_value,blocks[i+1]->hash_value)));
                blocks[i]->parent = nodes[n];
                blocks[i+1]->parent = nodes[n];
                nodes[n]->left = blocks[i];
                nodes[n]->right = blocks[i+1];
            }else{
                nodes.push_back(new MerkleTreeNode(ahash_sha256(blocks[i]->hash_value)));
                blocks[i]->parent = nodes[n];                
                nodes[n]->left = blocks[i];
            }
        }
        blocks = nodes;
        nodes.clear();
    }
    this->root = blocks[0];
    blocks.clear();
}

void MerkleTree::deleteTree(MerkleTreeNode* root)
{
    if (root != nullptr){
        deleteTree(root->left);
        deleteTree(root->right);
        root = nullptr;
        delete root;
    }
}

MerkleTree::~MerkleTree()
{
    deleteTree(this->root);
}

void MerkleTree::_PrintTree(MerkleTreeNode* node, int indent)
{
    if (node){
        if (node->left){
            _PrintTree(node->left,indent + 4);
        }
        if (indent){
            std::cout << std::setw(indent) << ' ';
        }
        std::cout << node->hash_value << "\n";
        if (node->right){
            _PrintTree(node->right,indent + 4);
        }
        
    }
}

void MerkleTree::PrintTree()
{
    _PrintTree(root,0);
}