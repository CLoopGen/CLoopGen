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
    IDWTELEM temp_low1, temp_low2;
    for (; (*i) >= 0; (*i) -= 2) {
        temp_low1 = high[(*i) >> 1];
        temp_low2 = low[(*i) >> 1];
        low[(*i) + 1] = temp_low1;
        low[*i] = temp_low2;
    }
}
