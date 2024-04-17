#ifndef DES_TEST_H
#define DES_TEST_H

#include <DES.h>
#include "test.h"

TestVector const testVectorDES = {
    .name = "DES",
    .key  = {0x3b, 0x38, 0x98, 0x37, 0x15, 0x20, 0xf7, 0x5e}
};

TestVector const testVectorTDES = {
    .name = "TDES",
    .key  = {0x3b, 0x38, 0x98, 0x37, 0x15, 0x20, 0xf7, 0x5e,
             0x92, 0x2f, 0xb5, 0x10, 0xc7, 0x1f, 0x43, 0x6e,
             0x3b, 0x38, 0x98, 0x37, 0x15, 0x20, 0xf7, 0x5e}
};

void perfDESCipher(const struct TestVector *test, bool trip);
void testDES();

#endif
