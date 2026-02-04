#include <stdio.h>

#include <inttypes.h>

extern signed char e[64];
extern signed char carry;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    signed char local_e, local_carry = carry;
    for (i = 0; i < 63; ++i) {
        local_e = e[i] + local_carry;
        local_carry = (local_e + 8) >> 4;
        e[i] = local_e - (local_carry << 4);
    }
    carry = local_carry;
}
