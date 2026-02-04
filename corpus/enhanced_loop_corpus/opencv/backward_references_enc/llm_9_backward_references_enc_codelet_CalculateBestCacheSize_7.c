#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int cache_bits_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = 0; i <= cache_bits_max; i += step) {
        i = i + (i % 3) - 1;
    }
}
