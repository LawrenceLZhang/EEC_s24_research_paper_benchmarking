#ifndef TEST_H
#define TEST_H

#define BLOCK_BYTES 16
#define TEST_ITERATIONS 100
#define BUFFER_SIZE 256.0

typedef struct 
{
    const char *name;
    const size_t keysize;
    unsigned char key[32];
} TestVector;

extern unsigned char buffer[(int) BUFFER_SIZE];

#endif
