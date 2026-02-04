#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t exp16_table[21];
extern uint64_t a;
extern int i;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 20; i >= 0; i--) {
        int64_t b = exp16_table[i];
        if (a < (b << 16))
            continue;
        out |= 1 << i;
        uint64_t quotient_part = (a / b) << 16;
        uint64_t remainder_part = ((a % b) << 16) + (b / 2);
        uint64_t correction = remainder_part / b;
        a = quotient_part + correction;
    }
}
