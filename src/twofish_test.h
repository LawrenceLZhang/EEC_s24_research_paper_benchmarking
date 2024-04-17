#ifndef TWOFISH_TEST_H
#define TWOFISH_TEST_H

#include <CryptoinoTwofish.h>
#include <CryptoinoCipher.h>
#include "test.h"

TestVector const testVectorTwofish = {
    .name = "Twofish",
    .key  = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
             0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F}
};

void perfTwofishCipher(const struct TestVector *test);
void perfTwofishCipher();

#endif