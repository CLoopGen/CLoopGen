#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;
extern long ss;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 200; j += 2) {
    x[j] = ss;
    x[j+1] = ss ^ 7; 
    ss <<= 2;
    if (ss >= (1L << 30))
        ss -= (1L << 30) - 4;
}
}
