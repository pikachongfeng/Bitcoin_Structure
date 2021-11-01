#ifndef BLOCK_H_
#define BLOCK_H_

#include <string>
#include <vector>

class Block
{
public:
    Block(std::vector<std::string> trans);
    Block(std::vector<std::string> trans,Block prev);
    ~Block(){};
    std::string blocksize;
    std::string blockhead;
    std::string trans_count;
    std::vector<std::string> transactions;
    std::string calc_size();
    std::string version;
    std::string prev_hash;
    std::string merkle_hash;
    std::string Timestamp;
    std::string Target;
    std::string Nounce;
private:
    std::string get_rawdata();
};
#endif