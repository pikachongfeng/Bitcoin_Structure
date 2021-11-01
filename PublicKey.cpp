#include "PublicKey.h"
#include "utils.h"
#include "secp256k1.h"

const unsigned int PUBLIC_KEY_SIZE = 65;
const unsigned int UNCOMPRESS_SIZE = 65;
const unsigned int SIGNATURE_SIZE = 72;

PublicKey::PublicKey(uint8_t* priv_key_data) : priv_keyByte(priv_key_data)
{
  ctx_ = secp256k1_context_create(SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);
  // Calculate public key from private key.
  CalculatePublicKey();
}

PublicKey::~PublicKey()
{
  secp256k1_context_destroy(ctx_);
  ctx_ = nullptr;
}

bool PublicKey::CalculatePublicKey() {
  // Calculate public key.
  secp256k1_pubkey pubkey;
  int ret = secp256k1_ec_pubkey_create(ctx_, &pubkey, priv_keyByte);

  // Serialize public key.
  size_t out_size = UNCOMPRESS_SIZE;
  public_key.resize(out_size);
  secp256k1_ec_pubkey_serialize(
      ctx_, public_key.data(), &out_size, &pubkey,SECP256K1_EC_UNCOMPRESSED);
  public_key.resize(out_size);
  // Succeed.
  return true;
}

std::vector<uint8_t> PublicKey::Sign(const uint8_t* str) {
  // Make signature
  int ret = secp256k1_ecdsa_sign(ctx_, &sig, str, priv_keyByte,secp256k1_nonce_function_rfc6979, nullptr);
  std::vector<uint8_t> sig_out;
  size_t sig_out_size = 72;
  sig_out.resize(sig_out_size);
  ret = secp256k1_ecdsa_signature_serialize_der(ctx_, sig_out.data(), &sig_out_size, &sig);
  sig_out.resize(sig_out_size);
  // Returns
  return sig_out;
}

bool PublicKey::VerifyKey(const uint8_t* sigature_str) {
  secp256k1_pubkey pubkey;
  int ret = secp256k1_ec_pubkey_create(ctx_, &pubkey, priv_keyByte);
  return secp256k1_ecdsa_verify(ctx_,&sig,sigature_str,&pubkey);
}
