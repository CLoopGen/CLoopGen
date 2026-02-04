#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int ch = 1048576; // ~1M iterations for ~0.01 sec runtime
uint8_t *do_not_decode;
unsigned int j;

void init_vars() {
    do_not_decode = aligned_alloc(32, sizeof(uint8_t) * ch);
    if (!do_not_decode) exit(1);
    for (unsigned int i = 0; i < ch; ++i) {
        do_not_decode[i] = (uint8_t)(i ^ 0xFF);
    }
}