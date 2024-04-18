#include <string.h>
#include "xtea_test.h"
#include "esp_timer.h"

XteaContext xtea;

void perfXTEACipher(XteaContext *context, const TestVector *test)
{
    int64_t start;
    int64_t elapsed;
    int count;

    xteaInit(context, test->key, sizeof(test->key));

    printf("%s Encrypting ... ", test->name);
    start = esp_timer_get_time();
    for (count = 0; count < TEST_ITERATIONS; ++count) {
        for (int blocks = 0; blocks < BUFFER_SIZE; blocks += BLOCK_BYTES) {
            xteaEncryptBlock(context, buffer + blocks, buffer + blocks);
        }
    }
    elapsed = esp_timer_get_time() - start;
    printf("%f us/B, ", elapsed / (TEST_ITERATIONS * BUFFER_SIZE));
    printf("%f MB/s\n", (BUFFER_SIZE * TEST_ITERATIONS) / elapsed);

    printf("%s Decrypting ... ", test->name);
    start = esp_timer_get_time();
    for (count = 0; count < TEST_ITERATIONS; ++count) {
        for (int blocks = 0; blocks < BUFFER_SIZE; blocks += BLOCK_BYTES) {
            xteaDecryptBlock(context, buffer + blocks, buffer + blocks);
        }
    }
    elapsed = esp_timer_get_time() - start;
    printf("%f us/B, ", elapsed / (TEST_ITERATIONS * BUFFER_SIZE));
    printf("%f MB/s\n", (BUFFER_SIZE * TEST_ITERATIONS) / elapsed);
    printf("\n");

    xteaDeinit(context);
}
void testXTEA()
{
    perfXTEACipher(&xtea, &testVectorXTEA);
}
