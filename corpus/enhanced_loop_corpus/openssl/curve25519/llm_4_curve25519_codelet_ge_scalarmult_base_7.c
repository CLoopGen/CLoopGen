#include <stdio.h>

#include <inttypes.h>

extern signed char e[64];
extern signed char carry;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 63; ++i) {
        if (i % 2 == 0) {
            e[i] += carry;
            carry = e[i] + 8;
            carry >>= 4;
            e[i] -= carry << 4;
        } else {
            signed char temp = e[i] + carry;
            signed char shift = (temp + 8) >> 4;
            e[i] = temp - (shift << 4);
            carry = shift;
        }
    }
}
