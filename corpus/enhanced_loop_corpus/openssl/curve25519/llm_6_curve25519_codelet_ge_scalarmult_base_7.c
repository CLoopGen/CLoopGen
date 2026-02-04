#include <stdio.h>

#include <inttypes.h>

extern signed char e[64];
extern signed char carry;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    signed char temp;
    for (i = 0; i < 63; ++i) {
        temp = e[i] + carry;
        carry = temp + 8;
        carry >>= 4;
        e[i] = temp - (carry << 4);
    }
}
