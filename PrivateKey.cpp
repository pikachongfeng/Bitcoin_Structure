#include "PrivateKey.h"
#include "SHA256.h"
#include "utils.h"
#include <vector>
#include <string>


PrivateKey::PrivateKey(std::string input)
{
    SHA256 sha;
    sha.update(input);
    private_key = sha.digest();
}

uint8_t* PrivateKey::get() const
{
    return private_key;
}
