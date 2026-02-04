#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int k;
extern int xbit[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp_i;
for (k = 0; k < 31; ++k) {
    temp_i = i >> k;
    xbit[k] = temp_i & 1;
}
}
