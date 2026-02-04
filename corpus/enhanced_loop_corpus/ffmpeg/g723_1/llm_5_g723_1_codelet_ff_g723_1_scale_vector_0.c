#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *vector;
extern int length;
extern int max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    max = 0;
    for (i = 0; i < length; i++) {
        int16_t val = vector[i];
        int16_t abs_val = val;
        if (val < 0) {
            abs_val = -val;
        }
        max |= abs_val;
    }
}
