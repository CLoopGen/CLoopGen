#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t random_dequant_type24[128][3];
int i;
int j;
uint32_t ldw;
uint64_t random_seed;

void init_vars() {
    // No additional initialization needed beyond zeroing or default static init
    // The loop() function initializes all necessary values at runtime
}