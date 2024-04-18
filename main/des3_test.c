#include <string.h>
#include "des3_test.h"
#include "esp_timer.h"

Des3Context des3;

void perfDES3Cipher(Des3Context *context, const TestVector *test)
{
    int64_t start;
    int64_t elapsed;
    int count;

    des3Init(context, test->key, sizeof(test->key));

    printf("%s Encrypting ... ", test->name);
    start = esp_timer_get_time();
    for (count = 0; count < TEST_ITERATIONS; ++count) {
        for (int blocks = 0; blocks < BUFFER_SIZE; blocks += BLOCK_BYTES) {
            des3EncryptBlock(context, buffer + blocks, buffer + blocks);
        }
    }
    elapsed = esp_timer_get_time() - start;
    printf("%f us/B, ", elapsed / (TEST_ITERATIONS * BUFFER_SIZE));
    printf("%f MB/s\n", (BUFFER_SIZE * TEST_ITERATIONS) / elapsed);

    printf("%s Decrypting ... ", test->name);
    start = esp_timer_get_time();
    for (count = 0; count < TEST_ITERATIONS; ++count) {
        for (int blocks = 0; blocks < BUFFER_SIZE; blocks += BLOCK_BYTES) {
            des3DecryptBlock(context, buffer + blocks, buffer + blocks);
        }
    }
    elapsed = esp_timer_get_time() - start;
    printf("%f us/B, ", elapsed / (TEST_ITERATIONS * BUFFER_SIZE));
    printf("%f MB/s\n", (BUFFER_SIZE * TEST_ITERATIONS) / elapsed);
    printf("\n");

    des3Deinit(context);
}
void testDES3()
{
    perfDES3Cipher(&des3, &testVectorDES3);
}
