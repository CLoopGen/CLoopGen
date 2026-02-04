#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int num_tests;
uint32_t seed;
int remaining_tests[117600];
int max_tests;
int test;

void init_vars() {
    max_tests = 117600;
    num_tests = 50000;
    seed = 123456789;

    for (int i = 0; i < max_tests; i++) {
        remaining_tests[i] = i;
    }
}