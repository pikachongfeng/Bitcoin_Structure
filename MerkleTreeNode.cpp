#include "MerkleTreeNode.h"

MerkleTreeNode::MerkleTreeNode(std::string data):hash_value(data),left(nullptr),right(nullptr),parent(nullptr)
{
}