#include <Arduino.h>
#include <string.h>
#include "aes_test.h"

#define BLOCK_BYTES 16

AesContext aes128;
AesContext aes192;
AesContext aes256;

void perfAESCipher(AesContext *context, const struct TestVector *test)
{
    unsigned long start;
    unsigned long elapsed;
    int count;

    aesInit(context, test->key, sizeof(test->key));

    Serial.print(test->name);
    Serial.print(" Encrypting ... ");
    start = micros();
    for (count = 0; count < TEST_ITERATIONS; ++count) {
        for (int blocks = 0; blocks < BUFFER_SIZE; blocks += BLOCK_BYTES) {
            aesEncryptBlock(context, buffer + blocks, buffer + blocks + BLOCK_BYTES);
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
        for (int blocks = 0; blocks < BUFFER_SIZE; blocks += BLOCK_BYTES) {
            aesDecryptBlock(context, buffer + blocks, buffer + blocks + BLOCK_BYTES);
        } 
    }
    elapsed = micros() - start;
    Serial.print(elapsed / (TEST_ITERATIONS * BUFFER_SIZE));
    Serial.print("us per byte, ");
    Serial.print((BUFFER_SIZE * TEST_ITERATIONS * 1000000.0) / elapsed);
    Serial.println(" bytes per second");

    Serial.println();
}

void testAES()
{
    perfAESCipher(&aes128, &testVectorAES128);
    perfAESCipher(&aes192, &testVectorAES192);
    perfAESCipher(&aes256, &testVectorAES256);
}
