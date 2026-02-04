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
for (; (*i) >= 0; ) {
    for (int unroll = 0; unroll < 2 && (*i) >= 0; ++unroll, (*i) -= 2) {
        low[(*i) + 1] = high[(*i) >> 1];
        low[*i] = low[(*i) >> 1];
    }
}
}
