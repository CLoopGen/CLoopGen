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
for (test = 0; test < num_tests; test++) {
    unsigned int r;
    ((seed) = (seed) * 1664525 + 1013904223);
    r = (seed * (uint64_t)(max_tests - test)) >> 32;
    do {
        int SWAP_tmp = remaining_tests[max_tests - test - 1];
        remaining_tests[max_tests - test - 1] = remaining_tests[r];
        remaining_tests[r] = SWAP_tmp;
    } while (0);
}

}
