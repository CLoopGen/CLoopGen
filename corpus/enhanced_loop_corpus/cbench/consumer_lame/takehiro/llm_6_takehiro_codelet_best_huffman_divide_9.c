#include <stdio.h>

#include <inttypes.h>

extern int r0;
extern int r3_bits[25];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (; r0 <= 7 + 15 + 2; r0++) {
        temp = r3_bits[r0] + 1;  // Introduce RAW dependency: current iteration reads previous write via temp
        r3_bits[r0] = temp * 1000; // WAW with itself across iterations (loop-carried)
    }
}
