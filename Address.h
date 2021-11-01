#ifndef ADDRESS_H_
#define ADDRESS_H_

#include <vector>
#include <string>

class Address
{
public:
    Address(std::vector<uint8_t> pub_key);
    ~Address();
    std::string get() const;
    std::string getBase58();

private:
    std::string address;
    std::string GetXaddress(std::string address);
    std::string GetXaddressChecksum(std::string xaddress);
    std::string XaddressToWif(std::string xaddress);
    std::string WifToBase58(std::string wif);
    std::string RIPEMD160(std::string pub_key);
};

#endif