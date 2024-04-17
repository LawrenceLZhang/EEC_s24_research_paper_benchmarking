#include <Arduino.h>
#include "test.h"

#define TEST_BLOWFISH

#if defined(TEST_AES)
    #include "aes_test.h"
#elif defined(TEST_DES)
    #include "des_test.h"
#elif defined(TEST_BLOWFISH)
    #include "blowfish_test.h"
#elif defined(TEST_XXTEA)
    #include "xxtea_test.h"
#endif

byte buffer[(int) BUFFER_SIZE];

void setup()
{
    Serial.begin(9600);

	Serial.println();
    Serial.println("Performance Tests:");

    #if defined(TEST_AES)
        testAES();
    #elif defined(TEST_DES)
        testDES();
    #elif defined(TEST_BLOWFISH)
        testBlowfish();
    #elif defined(TEST_BLOWFISH)
        testBlowfish();
    #elif defined(TEST_XXTEA)
        testXXTEA();
    #endif
}

void loop() {}