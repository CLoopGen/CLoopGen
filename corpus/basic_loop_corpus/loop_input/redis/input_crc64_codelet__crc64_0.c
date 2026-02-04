#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint_fast64_t crc = 0;
uint64_t len = 0;
uint8_t *data = NULL;
unsigned long long bit = 0;

void init_vars() {
    len = 134217728; // 128 MB, tuned for ~0.01 sec on modern CPU with compiler optimizations
    data = (uint8_t *)aligned_alloc(32, len);
    if (!data) {
        exit(1);
    }
    for (uint64_t i = 0; i < len; i++) {
        data[i] = (uint8_t)(i & 255);
    }
    crc = 0xABCDEF0123456789ULL;
    bit = 0;
}