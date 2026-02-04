#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    uint32_t state[5];
    uint32_t count[2];
    unsigned char buffer[64];
} SHA1_CTX;

unsigned char digest[20];
SHA1_CTX *context;
unsigned int i;

void init_vars() {
    context = (SHA1_CTX*)malloc(sizeof(SHA1_CTX));
    if (!context) {
        exit(1);
    }
    for (int j = 0; j < 5; j++) {
        context->state[j] = 0x12345678U ^ (j << 20);
    }
    for (int j = 0; j < 2; j++) {
        context->count[j] = 0;
    }
    for (int j = 0; j < 64; j++) {
        context->buffer[j] = (unsigned char)(j & 0xFF);
    }
    for (int j = 0; j < 20; j++) {
        digest[j] = 0;
    }
    i = 0;
}