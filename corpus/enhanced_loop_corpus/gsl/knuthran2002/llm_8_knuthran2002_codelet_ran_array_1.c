#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long aa[];
extern unsigned int n;
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int step = 2;
    for (; j < n; j += step)
        if (j >= 100) 
            aa[j] = (((aa[j - 100]) - (aa[j - 37])) & ((1L << 30) - 1));
}
