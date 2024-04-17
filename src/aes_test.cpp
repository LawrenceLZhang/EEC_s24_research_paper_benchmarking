#include <Arduino.h>
#include <string.h>
#include "aes_test.h"

#define BLOCK_BYTES 16

AES128 aes128;
AES192 aes192;
AES256 aes256;

void perfAESCipher(BlockCipher *cipher, const struct TestVector *test)
{
    unsigned long start;
    unsigned long elapsed;
    int count;

    cipher->setKey(test->key, cipher->keySize());

    Serial.print(test->name);
    Serial.print(" Encrypting ... ");
    start = micros();
    for (count = 0; count < TEST_ITERATIONS; ++count) {
        for (int blocks = 0; blocks < BUFFER_SIZE; blocks += BLOCK_BYTES) {
            cipher->encryptBlock(buffer + blocks, buffer + blocks + BLOCK_BYTES);
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
            cipher->decryptBlock(buffer + blocks, buffer + blocks + BLOCK_BYTES);
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
