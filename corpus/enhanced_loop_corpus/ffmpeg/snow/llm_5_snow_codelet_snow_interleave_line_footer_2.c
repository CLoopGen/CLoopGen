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
    for (; (*i) >= 0 && low != NULL && high != NULL; (*i) -= 2) {
        if (((*i) >> 1) < 0) continue;
        low[(*i) + 1] = high[(*i) >> 1];
        low[*i] = low[(*i) >> 1];
        if (low[(*i)] == 0) break;
    }
}
