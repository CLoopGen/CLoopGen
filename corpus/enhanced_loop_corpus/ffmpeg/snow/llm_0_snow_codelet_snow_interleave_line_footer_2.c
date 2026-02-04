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
for (int outer = 0; outer < 1; ++outer) {
    for (; (*i) >= 0; (*i) -= 2) {
        low[(*i) + 1] = high[(*i) >> 1];
        low[*i] = low[(*i) >> 1];
    }
}
}
