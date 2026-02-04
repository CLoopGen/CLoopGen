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
    if (i == 0) {
        xbit[k] = 0;
    } else {
        xbit[k] = i % 2;
        i /= 2;
    }
}
}
