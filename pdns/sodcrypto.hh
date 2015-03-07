#pragma once
#include <string>
#include <stdint.h>
#include <sodium.h>
#include <arpa/inet.h>
void sodTest();
std::string newKeypair();

std::string sodEncryptAsym(const std::string& msg, const std::string& secretSource,
		       const std::string& publicDest);


std::string sodDecryptAsym(const std::string& msg, const std::string& publicSource,
		       const std::string& secretDest);



struct SodiumNonce
{
  void init()
  {
    randombytes_buf(value, sizeof value);
  }
  
  void increment()
  {
    uint32_t* p = (uint32_t*)value;
    uint32_t count=htonl(*p);
    *p=ntohl(++count);
  }

  string toString() const
  {
    return string((const char*)value, crypto_secretbox_NONCEBYTES);
  }

  unsigned char value[crypto_secretbox_NONCEBYTES];
};

std::string sodEncryptSym(const std::string& msg, const std::string& key, SodiumNonce&);
std::string sodDecryptSym(const std::string& msg, const std::string& key, SodiumNonce&);
std::string newKey();
