#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float noise_table[4116];
int i;
uint64_t random_seed;
float delta;

void init_vars() {
    random_seed = 123456789ULL;
    delta = 0.00006103515625f;  // Example value: 1/16384
}