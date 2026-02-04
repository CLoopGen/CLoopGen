#include <stdio.h>

#include <inttypes.h>

extern signed char e[64];
extern signed char carry;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32; ++i) {
    e[i] += carry;
    carry = e[i] + 12;
    carry >>= 3;
    e[i] -= carry << 3;
    e[i+1] += carry;
}
}
