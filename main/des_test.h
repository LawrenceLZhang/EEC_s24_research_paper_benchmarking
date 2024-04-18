#ifndef DES_TEST_H
#define DES_TEST_H

#include <core/crypto.h>
#include <cipher/des.h>
#include "test.h"

static const TestVector testVectorDES = {
    "DES",
    8,
    {0x3b, 0x38, 0x98, 0x37, 0x15, 0x20, 0xf7, 0x5e}
};

void perfDESCipher(DesContext *context, const TestVector *test);
void testDES();

#endif