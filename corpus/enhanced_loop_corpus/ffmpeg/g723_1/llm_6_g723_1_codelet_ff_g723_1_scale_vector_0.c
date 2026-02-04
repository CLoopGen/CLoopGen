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
    int16_t local_max = max;
    for (i = 0; i < length; i++) {
        int16_t abs_val = (vector[i] >= 0) ? vector[i] : -vector[i];
        local_max |= abs_val;
    }
    max = local_max;
}
