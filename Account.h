#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <string>
#include <vector>

class PrivateKey;
class PublicKey;
class Address;

class Account
{
public:
    Account(std::string input);
    ~Account();
    uint8_t* get_private_key() const;
    std::string see_private_key() const;
    std::string get_public_key() const;
    std::string get_address() const {return address; }
       
private:
    uint8_t* private_key;
    std::vector<uint8_t> public_key;
    std::string address;
};

#endif