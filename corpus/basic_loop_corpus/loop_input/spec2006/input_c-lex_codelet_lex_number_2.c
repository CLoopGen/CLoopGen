#include <stdio.h>
#include <inttypes.h>
#include <string.h>

unsigned int parts[16];
long high;
long low;
int i;

void init_vars() {
    // Initialize parts array with non-zero values to ensure meaningful bitwise operations
    for (int idx = 0; idx < 16; idx++) {
        parts[idx] = 0xdeadbeefU ^ (idx << 2);
    }
    // Initialize high and low to zero to ensure defined behavior with |=
    high = 0;
    low = 0;
    i = 0;
}