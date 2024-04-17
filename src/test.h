#ifndef TEST_H
#define TEST_H

#define TEST_ITERATIONS 100
#define BUFFER_SIZE 256.0

struct TestVector
{
    const char *name;
    byte key[32];
};

extern byte buffer[(int) BUFFER_SIZE];

#endif
