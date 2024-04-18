#include <string.h>
#include "aes_test.h"
#include "esp_timer.h"



AesContext aeshw128;
AesContext aeshw192;
AesContext aeshw256;

void perfAESHWCipher(AesContext *context, const TestVector *test)
{
    int64_t start;
    int64_t elapsed;
    int count;

    esp32CryptoInit();
    aesInit(context, test->key, test->keysize);

    printf("%s Encrypting ... ", test->name);
    start = esp_timer_get_time();
    for (count = 0; count < TEST_ITERATIONS; ++count) {
        for (int blocks = 0; blocks < BUFFER_SIZE; blocks += BLOCK_BYTES) {
            aesEncryptBlock(context, buffer + blocks, buffer + blocks);
        }
    }
    elapsed = esp_timer_get_time() - start;
    printf("%f us/B, ", elapsed / (TEST_ITERATIONS * BUFFER_SIZE));
    printf("%f MB/s\n", (BUFFER_SIZE * TEST_ITERATIONS) / elapsed);

    printf("%s Decrypting ... ", test->name);
    start = esp_timer_get_time();
    for (count = 0; count < TEST_ITERATIONS; ++count) {
        for (int blocks = 0; blocks < BUFFER_SIZE; blocks += BLOCK_BYTES) {
            aesDecryptBlock(context, buffer + blocks, buffer + blocks);
        }
    }
    elapsed = esp_timer_get_time() - start;
    printf("%f us/B, ", elapsed / (TEST_ITERATIONS * BUFFER_SIZE));
    printf("%f MB/s\n", (BUFFER_SIZE * TEST_ITERATIONS) / elapsed);
    printf("\n");

    aesDeinit(context);
}
void testAESHW()
{
    perfAESHWCipher(&aeshw128, &testVectorAES128);
    perfAESHWCipher(&aeshw192, &testVectorAES192);
    perfAESHWCipher(&aeshw256, &testVectorAES256);
}
