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
    int j;
    for (j = *i; j >= 0; j--) {
        if (j & 1) continue;
        IDWTELEM temp_high = high[j >> 1];
        IDWTELEM temp_low = low[j >> 1];
        low[j + 1] = temp_high;
        low[j] = temp_low;
    }
    *i = -1;
}
