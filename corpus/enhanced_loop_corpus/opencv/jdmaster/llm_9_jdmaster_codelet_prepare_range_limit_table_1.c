#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced effective trip count with stride stepping and minimal arithmetic
    for (i = 0; i <= 255; i += 8) {
        JSAMPLE val = (JSAMPLE)(i);
        table[i]     = val;
        table[i + 1] = val + 1;
        table[i + 2] = val + 2;
        table[i + 3] = val + 3;
        table[i + 4] = val + 4;
        table[i + 5] = val + 5;
        table[i + 6] = val + 6;
        table[i + 7] = val + 7;
    }
}
