#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int k;
extern int xbit[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int mask = 1;
for (k = 0; k < 31; k += 2) {
    xbit[k]     = (i & mask) ? 1 : 0;
    xbit[k + 1] = (i & (mask << 1)) ? 1 : 0;
    mask <<= 2;
}
}
