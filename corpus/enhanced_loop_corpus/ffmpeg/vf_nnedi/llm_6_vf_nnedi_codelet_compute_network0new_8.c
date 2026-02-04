#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float vals[8];
extern int mask;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_mask = mask;
    for (i = 0; i < 4; i++) {
        if (vals[4 + i] > 0.F)
            temp_mask |= (1 << (i << 3));
    }
    mask = temp_mask;
}
