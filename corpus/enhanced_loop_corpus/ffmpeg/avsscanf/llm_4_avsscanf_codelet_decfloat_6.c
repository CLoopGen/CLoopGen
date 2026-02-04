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
for (k = (z - 1 & (128 - 1)); ; k = (k - 1 & (128 - 1))) {
    uint64_t tmp = ((uint64_t)x[k] << 29) + carry;
    carry = tmp / 1000000000;
    x[k] = tmp % 1000000000;
    if (tmp <= 1000000000) {
        carry = 0;
    }
    if (k == (z - 1 & (128 - 1)) && k != a && !x[k]) {
        z = k;
    }
    if (k == a)
        break;
}
}
