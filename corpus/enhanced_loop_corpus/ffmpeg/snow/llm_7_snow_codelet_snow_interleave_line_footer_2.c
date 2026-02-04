#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern int *i;
extern IDWTELEM *low;
extern IDWTELEM *high;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    IDWTELEM *local_low = low;
    IDWTELEM *local_high = high;
    int local_i = *i;
    for (; local_i >= 0; local_i -= 2) {
        local_low[local_i] = local_low[local_i >> 1];
        local_low[local_i + 1] = local_high[local_i >> 1];
    }
    *i = local_i;
}
