#include <stdio.h>

#include <inttypes.h>

extern int r0;
extern int r3_bits[25];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 1; outer++) {
        for (; r0 <= 7 + 15 + 2; r0++) {
            r3_bits[r0] = 100000;
        }
    }
}
