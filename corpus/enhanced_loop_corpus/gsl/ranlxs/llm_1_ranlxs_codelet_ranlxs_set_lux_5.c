#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int k;
extern int xbit[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp_i = i;
k = 0;
for (int outer = 0; outer < 1; ++outer) { // Artificially nested: entire original loop placed inside a single-iteration outer loop
    for (; k < 31; ++k) {
        xbit[k] = temp_i % 2;
        temp_i /= 2;
    }
}
}
