#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int k;
extern int xbit[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 62; k += 2) {
    xbit[k/2] = (i >> (k/2)) & 1;
    i = (i > 0) ? i / 2 : i;
}
}
