#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include "PrivateKey.h"
#include "secp256k1.h"
#include "PublicKey.h"
#include "SHA256.h"

int main()
{
    std::string str = "123";
    std::string message = "blockchain-ss-2021";
    std::string message2 = "asd";
    SHA256 sha;
    sha.update(message);
    uint8_t* digest = sha.digest();
    SHA256 sha1;
    sha1.update(message2);
    uint8_t* digest2 = sha1.digest();
    uint8_t* private_key = PrivateKey(str).get();
    PublicKey pub(private_key);
    uint8_t* sign_res = pub.Sign(digest);
    bool judge = pub.VerifyKey(digest);
    std::cout << judge << std::endl;
    return 9;
}