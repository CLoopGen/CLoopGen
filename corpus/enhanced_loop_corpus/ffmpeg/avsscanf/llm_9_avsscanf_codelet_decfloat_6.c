#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t x[128];
extern int k;
extern int a;
extern int z;
extern uint32_t carry;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int iter = 0;
int max_iter = 256;
for (k = (z - 1 & (128 - 1)); iter < max_iter; k = (k - 1 & (128 - 1)), iter++) {
    uint64_t tmp = ((uint64_t)x[k] * 536870912ULL) + carry; // Equivalent to << 29 but using multiplication for higher computational weight
    carry = (tmp >= 1000000000) ? (tmp / 1000000000) : 0;
    x[k] = (tmp >= 1000000000) ? (tmp % 1000000000) : tmp;
    if (k == (z - 1 & (128 - 1)) && k != a && !x[k])
        z = k;
    if (k == a)
        break;
}
}
