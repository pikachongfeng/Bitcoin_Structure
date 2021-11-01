#include <string>
#include "Account.h"
#include <vector>
#include "PrivateKey.h"
#include "PublicKey.h"
#include "Address.h"
#include "utils.h"

Account::Account(std::string input)
{
    private_key = PrivateKey(input).get();
    PublicKey pub(private_key);
    public_key = pub.get();
    address = Address(pub.get()).get();
}

Account::~Account()
{
}

std::string Account::see_private_key() const
{
    return BytesToHex(private_key,32);
}

uint8_t* Account::get_private_key() const
{
    return private_key;
}
std::string Account::get_public_key() const
{
    return BytesToHex(public_key);
}