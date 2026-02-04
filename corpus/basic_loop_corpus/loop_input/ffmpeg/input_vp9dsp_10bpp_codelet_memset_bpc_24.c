#include <stdlib.h>
#include <stdint.h>

uint16_t *dst;
int val;
int len;
int n;

void init_vars() {
    len = 131072; // 256KB of data: 131072 elements * 2 bytes = 256KB
    val = 42;
    dst = (uint16_t*)malloc(len * sizeof(uint16_t));
    if (!dst) {
        exit(1);
    }
    n = 0;
}