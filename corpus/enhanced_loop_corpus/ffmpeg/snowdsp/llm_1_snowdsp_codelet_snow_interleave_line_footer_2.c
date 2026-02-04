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
    for (int outer = (*i + 1) / 2; outer > 0; --outer) {
        int idx = (outer - 1) * 2;
        low[idx + 1] = high[idx >> 1];
        low[idx] = low[idx >> 1];
    }
    *i = -1;
}
