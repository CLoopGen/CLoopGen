#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num_tests;
extern uint32_t seed;
extern int remaining_tests[117600];
extern int max_tests;
extern int test;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
unsigned int local_seed = seed;
for (test = 0; test < num_tests; test++) {
    local_seed = local_seed * 1664525 + 1013904223;
    unsigned int r = (local_seed * (uint64_t)(max_tests - test)) >> 32;
    int idx = max_tests - test - 1;
    if (r < max_tests) {
        int temp = remaining_tests[idx];
        remaining_tests[idx] = remaining_tests[r];
        remaining_tests[r] = temp;
    }
}
seed = local_seed; 
}
