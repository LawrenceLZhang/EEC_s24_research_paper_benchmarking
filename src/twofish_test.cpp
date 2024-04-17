// #include <Arduino.h>
// #include <string.h>
// #include "twofish_test.h"

// Cipher cipher;

// void perfTwofishCipher(const struct TestVector *test)
// {
//     unsigned long start;
//     unsigned long elapsed;
//     int count;

//     tf.Initialize((unsigned char *) test->key, 16);

//     Serial.print(test->name);
//     Serial.print(" Encrypting ... ");
//     start = micros();
//     for (count = 0; count < TEST_ITERATIONS; ++count) {
//         tf.Encode((unsigned char *) buffer, (unsigned char *) buffer, BUFFER_SIZE);
//     }
//     elapsed = micros() - start;
//     Serial.print(elapsed / (TEST_ITERATIONS * BUFFER_SIZE));
//     Serial.print("us per byte, ");
//     Serial.print((BUFFER_SIZE * TEST_ITERATIONS * 1000000.0) / elapsed);
//     Serial.println(" bytes per second");

//     Serial.print(test->name);
//     Serial.print(" Decrypting ... ");
//     start = micros();
//     for (count = 0; count < TEST_ITERATIONS; ++count) {
//         tf.Decode((unsigned char *) buffer, (unsigned char *) buffer, BUFFER_SIZE);
//     }
//     elapsed = micros() - start;
//     Serial.print(elapsed / (TEST_ITERATIONS * BUFFER_SIZE));
//     Serial.print("us per byte, ");
//     Serial.print((BUFFER_SIZE * TEST_ITERATIONS * 1000000.0) / elapsed);
//     Serial.println(" bytes per second");

//     Serial.println();
// }

// void testTwofish()
// {
//     perfTwofishCipher(&testVectorTwofish);
// }
