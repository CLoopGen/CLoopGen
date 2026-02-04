#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 100 + 100 - 2; j >= 100; j--) {
    int idx1 = j - (100 - 37);
    int idx2 = j;
    int idx3 = j - 100;
    x[idx1] = (((x[idx1]) - (x[idx2])) & ((1L << 30) - 1));
    x[idx3] = (((x[idx3]) - (x[idx2])) & ((1L << 30) - 1));
}
}
