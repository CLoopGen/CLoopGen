#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t x[128];
int k;
int a;
int z;
int rp;
int p10;
uint32_t carry;

void init_vars() {
    // Initialize scalar variables to ensure loop runs with valid bounds
    a = 0;
    z = 64;  // z must be greater than a to enter the loop, and k < 128
    rp = 900;
    p10 = 100000000;  // 10^8, so that 1000000000 / p10 is 10, avoiding division by zero or large values
    carry = 0;

    // Initialize array x with non-zero values to avoid immediate skipping in condition
    for (int i = 0; i < 128; i++) {
        x[i] = (uint32_t)(i * 17 + 1);  // Arbitrary non-zero pattern
    }

    // Ensure first element allows potential adjustment of 'a' and 'rp' in loop
    x[a] = 1;  // So that x[k] / p10 + carry might become zero if needed
}