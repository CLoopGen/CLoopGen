#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mul_3x5[125];
extern int x1;
extern int x2;
extern int x3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x3 = 0; x3 < 5; x3++)
        for (x2 = 0; x2 < 5; x2++)
            for (x1 = 0; x1 < 5; x1++) {
                int idx = x1 + x2 * 5 + x3 * 25;
                int val = x1 + (x2 << 4) + (x3 << 8);
                mul_3x5[idx] = val * val; // Increased arithmetic intensity: square the result
            }
}
