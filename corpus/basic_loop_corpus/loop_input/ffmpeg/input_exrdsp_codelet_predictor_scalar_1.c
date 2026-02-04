#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

uint8_t *src;
ptrdiff_t size;
ptrdiff_t i;

void init_vars() {
    size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec on modern CPUs
    src = aligned_alloc(32, size * sizeof(uint8_t));
    if (!src) {
        exit(1);
    }
    for (ptrdiff_t j = 0; j < size; j++) {
        src[j] = rand() % 256;
    }
}