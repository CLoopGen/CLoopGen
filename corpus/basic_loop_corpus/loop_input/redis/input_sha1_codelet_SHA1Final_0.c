#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    uint32_t state[5];
    uint32_t count[2];
    unsigned char buffer[64];
} SHA1_CTX;

unsigned char finalcount[8];
unsigned int i;

SHA1_CTX *context;
SHA1_CTX context_storage;

void init_vars() {
    context = &context_storage;
    context->count[0] = 0x12345678;
    context->count[1] = 0xABCDEF01;
    for (int j = 0; j < 5; j++) {
        context->state[j] = 0xCAFEBABE + j;
    }
    for (int j = 0; j < 64; j++) {
        context->buffer[j] = (unsigned char)(j % 256);
    }
    for (int j = 0; j < 8; j++) {
        finalcount[j] = 0;
    }
    i = 0;
}