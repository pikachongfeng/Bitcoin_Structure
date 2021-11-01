#include "transaction.h"
#include "utils.h"
#include "PublicKey.h"
#include "Address.h"
#include "SHA256.h"

using std::string;

Transaction::Transaction(uint8_t* private_byte) : version("01000000"),input("01"),locktime("000000000"),sequence("ffffffff"),vout("00000000"),output("01")
{
    PublicKey pub(private_byte);
    std::vector<uint8_t> pubKey = pub.get(); 
    std::string address = Address(pub.get()).get();
    SHA256 sha;
    sha.update(pre_sign());
    uint8_t* digest = sha.digest();
    std::vector<uint8_t> sig = pub.Sign(digest);
    txid = strRandHex(32);
    value = strRandHex(16);
    scriptPubKey = generate_scriptPubKey(address);
    scriptPubKeyLen = intToHex(scriptPubKey.size());
    scriptSig = genetate_scriptSig(BytesToHex(sig),BytesToHex(pubKey));
    scriptSigLen = intToHex(scriptSig.size());
}

Transaction::Transaction(string hash_pubkey,string sig, string pubKey) : version("01000000"),input("01"),locktime("000000000"),sequence("ffffffff"),vout("00000000"),output("01")
{
    txid = strRandHex(32);
    value = strRandHex(16);
    scriptPubKey = generate_scriptPubKey(hash_pubkey);
    scriptPubKeyLen = intToHex(scriptPubKey.size());
    scriptSig = genetate_scriptSig(sig,pubKey);
    scriptSigLen = intToHex(scriptSig.size());
}

string Transaction::get_PUSHDATA(long size)
{
    if (size > 0 && size < 76){
        return intToHex(size);
    }else if (size >= 76 && size < 2e8){
        return "4c" + intToHex(size);
    }else if (size >= 2e8 && size < 2e16){
        return "4d" + intToHex(size);
    }else if (size >= 2e16 && size < 2e32){
        return "4e" + intToHex(size);
    }
    return "";
}

string Transaction::generate_scriptPubKey(string hash_pubkey)
{
    string OP_DUP = "76";
    string OP_HASH160 = "a9";
    long size = hash_pubkey.size();
    std::string PUSHDATA = get_PUSHDATA(size);
    string OP_EQUALVERIFY = "88";
    string OP_CHECKSIG = "ac";
    return OP_DUP + OP_HASH160 + PUSHDATA + hash_pubkey + OP_EQUALVERIFY + OP_CHECKSIG;
}

string Transaction::genetate_scriptSig(string sig,string pubKey)
{
    long size = sig.size();
    std::string PUSHDATA = get_PUSHDATA(size);
    std::string SIGHASH = "01";
    return PUSHDATA + sig + SIGHASH + pubKey;
}