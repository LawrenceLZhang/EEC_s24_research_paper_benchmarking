#ifndef AES_TEST_H
#define AES_TEST_H

// #include <Crypto.h>
// #include <AES.h>
#include "test.h"

#include <crypto.h>
#include <cipher/aes.h>

TestVector const testVectorAES128 = {
    .name = "AES-128",
    .key  = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
             0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F}
};
TestVector const testVectorAES192 = {
    .name = "AES-192",
    .key = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
            0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17}
};
TestVector const testVectorAES256 = {
    .name = "AES-256",
    .key  = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
             0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
             0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
             0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F}
};

void perfAESCipher(AesContext *context, const struct TestVector *test);
void testAES();

#endif