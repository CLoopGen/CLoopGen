#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational frequency with stride-based iteration and combined arithmetic
    for (i = 0; i <= 255; i += 4) {
        table[i]     = (JSAMPLE)i;
        table[i + 1] = (JSAMPLE)(i + 1);
        table[i + 2] = (JSAMPLE)(i + 2);
        table[i + 3] = (JSAMPLE)(i + 3);
    }
}
