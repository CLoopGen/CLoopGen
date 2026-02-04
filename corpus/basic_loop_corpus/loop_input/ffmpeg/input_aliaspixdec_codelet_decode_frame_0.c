#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *out_buf;
uint8_t count;
int pixel;
int i;

void init_vars() {
    count = 256;
    pixel = 0x123456;
    out_buf = aligned_alloc(32, (size_t)count * 3);
    if (!out_buf) {
        exit(1);
    }
}

__attribute__((destructor))
static void cleanup() {
    free(out_buf);
}