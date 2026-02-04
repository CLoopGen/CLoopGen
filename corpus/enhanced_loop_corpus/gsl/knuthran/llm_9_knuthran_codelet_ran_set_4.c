#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;
extern long ss;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 50; j++) {
    x[j] = ss;
    ss += ss >> 1;
    ss ^= 0x12345;
    if (ss >= (1L << 29))
        ss = (ss >> 1) ^ 0xFFFF;
}
}
