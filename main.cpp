#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include "utils.h"
#include <ctime>
#include <string>
#include "Account.h"
#include "transaction.h"
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
    Block block1(trans1);
    std::vector<std::string> trans2(trans_string.begin()+100,trans_string.begin()+200);
    Block block2(trans2,block1);
    std::vector<std::string> trans3(trans_string.begin()+200,trans_string.begin()+300);
    Block block3(trans3,block2);
    std::vector<std::string> trans4(trans_string.begin()+300,trans_string.begin()+400);
    Block block4(trans4,block3);
    std::vector<std::string> trans5(trans_string.begin()+400,trans_string.begin()+500);
    Block block5(trans5,block4);
    std::vector<std::string> trans6(trans_string.begin()+500,trans_string.begin()+600);
    Block block6(trans6,block5);
    std::vector<std::string> trans7(trans_string.begin()+600,trans_string.begin()+700);
    Block block7(trans7,block6);
    std::vector<std::string> trans8(trans_string.begin()+700,trans_string.begin()+800);
    Block block8(trans8,block7);
    std::vector<std::string> trans9(trans_string.begin()+800,trans_string.begin()+900);
    Block block9(trans9,block8);
    std::vector<std::string> trans10(trans_string.begin()+900,trans_string.begin()+1000);
    Block block10(trans10,block9);

    std::cout << block10.blockhead << std::endl; //查看第9个区块的区块头
    return 0;
}