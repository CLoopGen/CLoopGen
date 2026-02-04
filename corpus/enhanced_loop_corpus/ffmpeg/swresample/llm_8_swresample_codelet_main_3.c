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
for (test = 0; test < num_tests; test += 2) {
    unsigned int r1, r2;
    seed = seed * 1664525 + 1013904223;
    r1 = (seed * (uint64_t)(max_tests - test)) >> 32;
    seed = seed * 1664525 + 1013904223;
    r2 = (seed * (uint64_t)(max_tests - test - 1)) >> 32;

    if (test < num_tests) {
        int SWAP_tmp = remaining_tests[max_tests - test - 1];
        remaining_tests[max_tests - test - 1] = remaining_tests[r1];
        remaining_tests[r1] = SWAP_tmp;
    }
    if (test + 1 < num_tests) {
        int SWAP_tmp = remaining_tests[max_tests - test - 2];
        remaining_tests[max_tests - test - 2] = remaining_tests[r2];
        remaining_tests[r2] = SWAP_tmp;
    }
}
}
