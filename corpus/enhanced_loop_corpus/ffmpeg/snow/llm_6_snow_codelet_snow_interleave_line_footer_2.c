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
    IDWTELEM temp_low, temp_high;
    for (; (*i) >= 0; (*i) -= 2) {
        temp_high = high[(*i) >> 1];
        temp_low = low[(*i) >> 1];
        low[(*i) + 1] = temp_high;
        low[*i] = temp_low;
    }
}
