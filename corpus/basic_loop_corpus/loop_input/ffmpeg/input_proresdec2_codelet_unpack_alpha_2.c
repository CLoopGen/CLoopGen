#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *dst;
int decode_precision;
int i;
int idx;
int val;
int alpha_val;

void init_vars() {
    val = 67108864; // ~64M iterations to target ~0.01 sec on modern CPU
    dst = (uint16_t*)aligned_alloc(32, val * sizeof(uint16_t));
    if (!dst) exit(1);
    idx = 0;
    decode_precision = 10;
    alpha_val = 0xABCD & 0xFF; // ensure only lower 8 bits matter per shift logic
}
// End of file