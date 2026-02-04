#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to handle even indices
    for (i = 0; i <= 255; i += 2) {
        table[i] = (JSAMPLE)i;
        if (i + 1 <= 255) {
            table[i + 1] = (JSAMPLE)(i + 1);
        }
    }
}
