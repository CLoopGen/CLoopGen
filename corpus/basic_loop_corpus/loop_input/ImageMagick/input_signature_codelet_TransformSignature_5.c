#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ssize_t i;
unsigned char *p;
unsigned int T;
unsigned int W[64];

static unsigned char data_buffer[256 << 20]; // 256 MB buffer

void init_vars() {
    for (size_t idx = 0; idx < sizeof(data_buffer); idx++) {
        data_buffer[idx] = rand() % 256;
    }
    p = data_buffer;
    T = 0;
    for (int j = 0; j < 64; j++) {
        W[j] = 0;
    }
    i = 0;
}