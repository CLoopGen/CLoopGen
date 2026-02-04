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
        if (j & 1) {
            low[j] = high[j >> 1];
        } else {
            low[j] = low[j >> 1];
        }
    }
    *i = -1;
}
