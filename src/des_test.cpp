#include <Arduino.h>
#include <string.h>
#include "des_test.h"

DES des;

void perfDESCipher(const struct TestVector *test, bool trip)
{
    unsigned long start;
    unsigned long elapsed;
    int count;

    Serial.print(test->name);
    Serial.print(" Encrypting ... ");
    start = micros();
    for (count = 0; count < TEST_ITERATIONS; ++count) {
        if (trip) des.tripleEncrypt(buffer, buffer, test->key);
        else des.encrypt(buffer, buffer, test->key);
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
        if (trip) des.tripleDecrypt(buffer, buffer, test->key);
        else des.decrypt(buffer, buffer, test->key);
    }
    elapsed = micros() - start;
    Serial.print(elapsed / (TEST_ITERATIONS * BUFFER_SIZE));
    Serial.print("us per byte, ");
    Serial.print((BUFFER_SIZE * TEST_ITERATIONS * 1000000.0) / elapsed);
    Serial.println(" bytes per second");

    Serial.println();
}

void testDES()
{
    perfDESCipher(&testVectorDES, false);
    perfDESCipher(&testVectorTDES, true);
}
