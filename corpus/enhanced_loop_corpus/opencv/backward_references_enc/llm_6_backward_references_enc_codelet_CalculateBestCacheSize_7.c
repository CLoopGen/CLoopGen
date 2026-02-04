#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int cache_bits_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i <= cache_bits_max; ++i) {
        temp += i;
    }
    // Introduces a loop-carried dependency (WAW on temp) and a RAW dependency (read i before use)
    // The result accumulates across iterations, creating a data dependency chain.
}
