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
for (; (*i) >= 0; (*i) -= 2) {
    IDWTELEM temp = high[(*i) >> 1];
    low[*i] = low[(*i) >> 1];
    low[(*i) + 1] = temp;
}
}
