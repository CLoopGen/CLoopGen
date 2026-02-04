#include <stdio.h>

#include <inttypes.h>

extern signed char e[64];
extern signed char carry;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 63; ++i) {
        carry = (e[i] += carry) + 8;
        if (carry > 0) {
            carry >>= 4;
            e[i] -= carry << 4;
        } else {
            carry = -( (-carry) >> 4 );
            if (carry != 0) e[i] -= carry << 4;
        }
    }
}
