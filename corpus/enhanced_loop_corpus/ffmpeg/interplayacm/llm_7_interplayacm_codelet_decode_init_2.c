#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mul_2x11[121];
extern int x1;
extern int x2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x2 = 0; x2 < 11; x2++) {
        int base_val = x2 << 4;
        for (x1 = 0; x1 < 11; x1++) {
            int idx = x1 + x2 * 11;
            mul_2x11[idx] = base_val + x1;
            if (idx > 0) 
                mul_2x11[idx] += (mul_2x11[idx - 1] & 0); // Artificial RAW dependency, no functional change
        }
    }
}
