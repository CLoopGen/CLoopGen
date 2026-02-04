#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t width;
int32_t w_cnt;

void init_vars() {
    // Set width to ensure loop runs enough iterations for ~0.01s runtime
    // Each iteration processes 16 elements; total data size should be around 1MB to 256MB
    // Assuming simple operations per iteration, pick a width of 4 million to get sufficient workload
    width = 4000000;  // Ensures w_cnt goes from 16 to ~4M in steps of 16 -> 250k iterations
}