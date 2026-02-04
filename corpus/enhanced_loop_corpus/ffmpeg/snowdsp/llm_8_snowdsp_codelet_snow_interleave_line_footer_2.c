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
    for (; idx >= 1; idx -= 4) {
        low[idx + 1] = high[idx >> 1];
        low[idx] = low[idx >> 1];
        if (idx >= 3) {
            low[idx - 1] = high[(idx - 2) >> 1];
            low[idx - 2] = low[(idx - 2) >> 1];
        }
    }
    *i = idx;
}
