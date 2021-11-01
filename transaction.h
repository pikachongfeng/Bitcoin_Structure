#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <string>
#include <vector>

using std::string;

class PublicKey;

class Transaction
{
public:
    Transaction(uint8_t* private_byte);
    Transaction(string hash_pubkey,string sig, string pubKey);
    ~Transaction() {};
    std::string pre_sign() const { return version + input + txid + vout + sequence + output + value + scriptPubKeyLen + scriptPubKey + locktime;}
    std::string get_rawTransaction() const { return version + input + txid + vout + scriptSigLen + scriptSig + sequence + output + value + scriptPubKeyLen + scriptPubKey + locktime;}
    std::string generate_scriptPubKey(std::string hash_pubkey);
    std::string genetate_scriptSig(std::string sig,std::string pubKey);
    std::string get_PUSHDATA(long size);
    std::string get_version() const { return version; }
    std::string get_input() const { return input; }
    std::string get_locktime() const { return locktime; }
    std::string get_txid() const { return txid; }
    std::string get_scriptSigLen() const { return scriptSigLen; }
    std::string get_vout() const { return vout; }
    std::string get_scriptSig() const { return scriptSig; }
    std::string get_sequence() const { return sequence; }
    std::string get_value() const { return value; }
    std::string get_scriptPubKey() { return scriptPubKey; }
    std::string get_output() { return output; }
    std::string get_scriptPubKeyLen() { return scriptPubKeyLen; }

private:
    std::string version;
    std::string input;
    std::string txid;
    std::string vout;
    std::string scriptSigLen;
    std::string scriptSig;
    std::string sequence;
    std::string output;
    std::string value;
    std::string scriptPubKeyLen;
    std::string scriptPubKey;
    std::string locktime;
};


#endif
