#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned long long mt[312];
unsigned long long i;
unsigned long long k;

void init_vars() {
    // Initialize the mt array with non-zero values to simulate realistic state
    for (int idx = 0; idx < 312; idx++) {
        mt[idx] = 123456789ULL + (idx * 987654321ULL);
    }
    // Initialize i and k to ensure the loop runs correctly
    i = 0;
    k = 312 - 1;
}