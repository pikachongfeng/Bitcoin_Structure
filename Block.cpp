#include "MerkleTree.h"
#include "utils.h"
#include "Block.h"
#include "SHA256.h"

Block::Block(std::vector<std::string> trans) : trans_count("64"),version("00000000"),Timestamp("00000000"),Target("00000000"),Nounce("00000000"),prev_hash("0000000000000000000000000000000000000000000000000000000000000000")
{
    transactions = trans;
    MerkleTree tree(trans);
    merkle_hash = tree.root->hash_value;
    blocksize = calc_size();
    blockhead = get_rawdata();
}

Block::Block(std::vector<std::string> trans,Block prev) : trans_count("64"),version("00000000"),Timestamp("00000000"),Target("00000000"),Nounce("00000000")
{
    transactions = trans;
    MerkleTree tree(trans);
    merkle_hash = tree.root->hash_value;
    blocksize = calc_size();
    prev_hash = hash_sha256(hash_sha256(prev.blockhead));
    blockhead = get_rawdata();
}

std::string Block::calc_size()
{
    int size = 0;
    for (int i =0 ;i < transactions.size(); ++i){
        size += transactions[i].size();
    }
    if (size % 2 != 0){
        ++size;
    }
    int res = size + size / 2 + 1 + 80;
    return intToHex(res);
}

std::string Block::get_rawdata()
{
    return version + prev_hash + merkle_hash + Timestamp + Target + Nounce;
}