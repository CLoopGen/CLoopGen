#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *in;
size_t size_in;
size_t extra;
size_t i;

void init_vars() {
    size_in = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec on modern CPU
    in = (uint8_t *)aligned_alloc(32, size_in);
    if (!in) {
        exit(1);
    }
    for (size_t idx = 0; idx < size_in; idx++) {
        in[idx] = rand() % 256;
    }
    extra = 0;
    i = 0;
}