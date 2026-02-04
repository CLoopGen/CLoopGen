#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float vals[8];
extern int mask;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        int shift_amount = i << 3;
        float val = vals[4 + i];
        if (val > 0.F)
            mask |= (1 << shift_amount);
    }
}
