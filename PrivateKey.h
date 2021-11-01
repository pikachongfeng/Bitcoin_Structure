#ifndef PRIVATEKEY_H_
#define PRIVATEKEY_H_

#include <string>
#include <vector>

class PrivateKey
{
public:
    PrivateKey(std::string input);
    ~PrivateKey() {};
    uint8_t* get() const;

private:
    uint8_t* private_key;
};

#endif