#include <Arduino.h>
#include <string.h>
#include "xxtea_test.h"

void perfXXTEACipher(const struct TestVector *test)
{
    unsigned long start;
    unsigned long elapsed;
    int count;

    xxtea_setup_key((uint8_t *) testVectorXXTEACipher.key, 16);
    size_t buffer_len = BUFFER_SIZE / 4;

    Serial.print(test->name);
    Serial.print(" Encrypting ... ");
    start = micros();
    for (count = 0; count < TEST_ITERATIONS; ++count) {
        for (int blocks = 0; blocks < 4; blocks ++) {
            xxtea_encrypt(buffer + blocks * buffer_len, buffer_len,
                    buffer + blocks * buffer_len, &buffer_len);
        }
    }
    elapsed = micros() - start;
    Serial.print(elapsed / (TEST_ITERATIONS * BUFFER_SIZE));
    Serial.print("us per byte, ");
    Serial.print((BUFFER_SIZE * TEST_ITERATIONS * 1000000.0) / elapsed);
    Serial.println(" bytes per second");

    Serial.print(test->name);
    Serial.print(" Decrypting ... ");
    start = micros();
    for (count = 0; count < TEST_ITERATIONS; ++count) {
        for (int blocks = 0; blocks < 4; blocks ++) {
            xxtea_decrypt(buffer + blocks * buffer_len, buffer_len);
        }
    }
    elapsed = micros() - start;
    Serial.print(elapsed / (TEST_ITERATIONS * BUFFER_SIZE));
    Serial.print("us per byte, ");
    Serial.print((BUFFER_SIZE * TEST_ITERATIONS * 1000000.0) / elapsed);
    Serial.println(" bytes per second");

    Serial.println();
}

void testXXTEA()
{
    perfXXTEACipher(&testVectorXXTEACipher);
}
