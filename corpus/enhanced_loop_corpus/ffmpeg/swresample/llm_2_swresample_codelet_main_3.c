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
    seed = seed * 1664525 + 1013904223;
    r = (seed * (uint64_t)(max_tests - test)) >> 32;
    int index1 = max_tests - test - 1;
    int index2 = r;
    int temp = remaining_tests[index1];
    remaining_tests[index1] = remaining_tests[index2];
    remaining_tests[index2] = temp;
}
}
