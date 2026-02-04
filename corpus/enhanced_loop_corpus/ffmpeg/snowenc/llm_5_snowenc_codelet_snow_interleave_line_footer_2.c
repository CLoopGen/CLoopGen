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
        if ((*i) < 0) break;
        low[(*i) + 1] = high[(*i) >> 1];
        low[*i] = low[(*i) >> 1];
        (*i) -= 2;
        if ((*i) == -1) (*i)--;
    }
}
