#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float vals[8];
extern int mask;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i += 2) {
        if (vals[4 + (i >> 1)] > 0.F && vals[5 + (i >> 1)] > 0.F)
            mask |= (1 << (i << 2));
    }
}
