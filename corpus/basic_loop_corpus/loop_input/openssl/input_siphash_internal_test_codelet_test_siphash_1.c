#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

unsigned char in[1024 * 512]; // 512 KB to target ~0.01 sec runtime
size_t inlen = 1024 * 512;
size_t i;

void init_vars() {
    // No additional initialization needed; variables are at file scope and already initialized
}