#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        int16_t val = block[i];
        int16_t abs_val = val;
        if (val < 0) abs_val = -val;
        sum += abs_val;
    }
}
