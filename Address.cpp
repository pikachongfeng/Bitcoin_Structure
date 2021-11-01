#include <string>
#include <vector>
#include "Address.h"
#include "SHA256.h"
#include "base58.h"
#include "ripemd160.h"
#include "utils.h"

std::string Address::GetXaddress(std::string address)
{
    std::string xaddress = "0x00";
    std::string addr(address.begin(),address.begin()+32);
    return xaddress + addr;
}

std::string Address::GetXaddressChecksum(std::string xaddress)
{
    std::string sha1 = hash_sha256(xaddress);
    std::string sha2 = hash_sha256(sha1);

    std::string checksum(sha2.begin(),sha2.begin()+4);
    return checksum;
}

std::string Address::XaddressToWif(std::string xaddress)
{
    std::string xaddWif(xaddress.begin(),xaddress.begin()+33);

    return xaddWif + GetXaddressChecksum(xaddress) ;
}

std::string Address::WifToBase58(std::string wif)
{
    return EncodeBase58(wif);
}

std::string Address::RIPEMD160(std::string pub_key){
    size_t msglen = 32;
    uint8_t msg[msglen];
    size_t hashlen = 20;
    uint8_t hash[hashlen];
    memcpy(msg, pub_key.c_str(), sizeof(msg));
    ripemd160(msg, msglen, hash);
    std::vector<uint8_t> hash_vec(&hash[0],&hash[hashlen]);
    std::string hexstr = BytesToHex(hash_vec);
    return hexstr;
}

Address::Address(std::vector<uint8_t> pub_key)
{
    address = RIPEMD160(hash_sha256(BytesToHex(pub_key)));
}

std::string Address::getBase58(){
    std::string base58address;
    base58address = WifToBase58(XaddressToWif(GetXaddress(hash_sha256(address))));
    return base58address;
}

Address::~Address()
{
    address.clear();
}

std::string Address::get() const
{
    return address;
}

