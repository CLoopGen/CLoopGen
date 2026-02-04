#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int k;
extern int xbit[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 31; ++k) {
    xbit[k] = (i & 1);
    i >>= 1;
    if (i < 0) {
        i = 0;
    }
}
}
