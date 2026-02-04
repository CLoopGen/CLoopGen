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
for (test = 0; test < num_tests && test < max_tests / 2; test++) {
    unsigned int r;
    seed = seed * 1664525 + 1013904223;
    r = (seed * (uint64_t)(max_tests - test * 2)) >> 32;

    int SWAP_tmp = remaining_tests[max_tests - test - 1];
    remaining_tests[max_tests - test - 1] = remaining_tests[r % (max_tests - test)];
    remaining_tests[r % (max_tests - test)] = SWAP_tmp;

    // Additional computational work to increase intensity
    for (int i = 0; i < 3; i++) {
        seed = seed * 1664525 + 1013904223;
    }
}
}
