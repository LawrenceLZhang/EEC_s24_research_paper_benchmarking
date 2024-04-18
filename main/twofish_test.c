#include <string.h>
#include "twofish_test.h"
#include "esp_timer.h"

TwofishContext tf;

void perfTwofishCipher(TwofishContext *context, const TestVector *test)
{
    int64_t start;
    int64_t elapsed;
    int count;

    twofishInit(context, test->key, sizeof(test->key));

    printf("%s Encrypting ... ", test->name);
    start = esp_timer_get_time();
    for (count = 0; count < TEST_ITERATIONS; ++count) {
        for (int blocks = 0; blocks < BUFFER_SIZE; blocks += BLOCK_BYTES) {
            twofishEncryptBlock(context, buffer + blocks, buffer + blocks);
        }
    }
    elapsed = esp_timer_get_time() - start;
    printf("%f us/B, ", elapsed / (TEST_ITERATIONS * BUFFER_SIZE));
    printf("%f MB/s\n", (BUFFER_SIZE * TEST_ITERATIONS) / elapsed);

    printf("%s Decrypting ... ", test->name);
    start = esp_timer_get_time();
    for (count = 0; count < TEST_ITERATIONS; ++count) {
        for (int blocks = 0; blocks < BUFFER_SIZE; blocks += BLOCK_BYTES) {
            twofishDecryptBlock(context, buffer + blocks, buffer + blocks);
        }
    }
    elapsed = esp_timer_get_time() - start;
    printf("%f us/B, ", elapsed / (TEST_ITERATIONS * BUFFER_SIZE));
    printf("%f MB/s\n", (BUFFER_SIZE * TEST_ITERATIONS) / elapsed);
    printf("\n");

    twofishDeinit(context);
}
void testTwofish()
{
    perfTwofishCipher(&tf, &testVectorTwofish);
}
