#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include "utils.h"
#include <ctime>
#include <string>
#include "Account.h"
#include "transaction.h"
#include "MerkleTree.h"
#include "Block.h"

using namespace std;

int main()
{
	int a[100];
	srand((unsigned)time(NULL));//设置种子
	for(int i=0;i<100;i++){
		a[i]=rand() % 100000000000; //生成100个随机数
    }
    std::vector<std::string> str; //生成100个随机字符串

    for (int i = 0; i < 100; ++i){
        str.push_back(intToHex(a[i]));
    }

    std::vector<Account> acc; //利用随机字符串生成100个账户
    for (int i = 0; i < 100; ++i){
        acc.push_back(Account(str[i]));
    }
    std::vector<Transaction> trans; //生成1000个随机交易
    for (int i = 0; i < 1000; ++i){
        int random = rand() % 100; //随机选择一个账户
        trans.push_back(Transaction(acc[random].get_private_key())); //用账户的私钥生成一笔随机交易
    }
    std::vector<std::string> trans_string;
    for (int i = 0; i < 1000; ++i){
        trans_string.push_back(trans[i].get_rawTransaction());
    }
    //依次生成10个区块
    std::vector<std::string> trans1(trans_string.begin(),trans_string.begin()+100);

    MerkleTree tree(trans1);
    std::string merkle_hash = tree.root->hash_value;
    std::cout << merkle_hash << std::endl;
    return 0;

}