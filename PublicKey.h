#ifndef PUBLICKEY_H_
#define PUBLICKEY_H_
#include "secp256k1.h"

#include <vector>
#include <string>

class secp256k1_context_struct;
typedef secp256k1_context_struct secp256k1_context;
class PublicKey
{
public:
    PublicKey(uint8_t* priv_key_data);
    ~PublicKey();
    std::vector<uint8_t>  get() { return public_key; }
    std::vector<uint8_t> Sign(const uint8_t* str);
    bool VerifyKey(const uint8_t* sigature_str);

private:
    bool CalculatePublicKey();
    uint8_t* CalculateuncomPublicKey();

private:
    uint8_t* priv_keyByte;
    std::vector<uint8_t> public_key;
    secp256k1_ecdsa_signature sig;
    secp256k1_context *ctx_ = nullptr;
};

#endif