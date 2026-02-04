#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float vals[8];
extern int mask;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        float sum = vals[4 + i] + vals[6 + i];
        if (sum > 0.F) {
            mask |= (1 << (i << 3));
            mask |= (1 << ((i + 1) << 3));
        }
    }
}
