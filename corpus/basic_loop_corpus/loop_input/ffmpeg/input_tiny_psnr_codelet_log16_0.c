#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint64_t exp16_table[21];
uint64_t a;
int i;
int out;

void init_vars() {
    // Initialize exp16_table with values: 2^(16 * i / 20) for i from 0 to 20
    for (int idx = 0; idx <= 20; idx++) {
        double val = 1.0;
        for (int pow = 0; pow < (16 * idx + 10) / 20; pow++) {
            val *= 2.0;
        }
        exp16_table[idx] = (uint64_t)(val + 0.5);
    }

    // Seed the input value 'a' to ensure meaningful computation
    a = 0x123456789ABCDEF0ULL;

    // Initialize loop control and output
    i = 0;
    out = 0;
}