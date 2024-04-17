#ifndef XXTEA_TEST_H
#define XXTEA_TEST_H

#include <xxtea-lib.h>
#include "test.h"

TestVector const testVectorXXTEACipher = {
    .name = "XXTEA",
    .key  = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
             0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F}
};

void perfXXTEACipher(const struct TestVector *test);
void testXXTEA();

#endif