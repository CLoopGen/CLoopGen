#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long aa[];
extern long ran_x[];
extern unsigned int i;
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < 50; i += 2, j += 2) {
        ran_x[i] = ((aa[j - 100] - ran_x[i - 37]) & ((1L << 30) - 1));
        if (i + 1 < 100) ran_x[i + 1] = ((aa[j - 99] - ran_x[i - 36]) & ((1L << 30) - 1));
    }
}
