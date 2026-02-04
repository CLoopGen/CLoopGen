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
    int idx = *i;
    for (; idx >= 2; idx -= 4) {
        low[idx - 1] = high[idx >> 2];
        low[idx - 2] = low[idx >> 2];
        low[idx + 0] = high[(idx - 2) >> 2];
        low[idx - 3] = low[(idx - 2) >> 2];
    }
    *i = idx;
}
