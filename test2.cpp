#include "PrivateKey.h"
#include "transaction.h"
#include "utils.h"
#include <iostream>

int main()
{
    std::string input = "123";
    uint8_t* private_key = PrivateKey(input).get();
    Transaction trans(private_key);
    std::cout << trans.get_rawTransaction();
}