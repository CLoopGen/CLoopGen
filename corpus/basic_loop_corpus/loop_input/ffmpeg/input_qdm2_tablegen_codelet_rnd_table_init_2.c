#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t random_dequant_index[256][5];
int i;
int j;
uint32_t ldw;
uint64_t random_seed;

void init_vars() {
    // No additional initialization needed beyond zero-initialization
    // The loop() function overwrites all values in the array and variables
}