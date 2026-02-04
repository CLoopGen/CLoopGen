#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2, traversing forward and backward to cover all indices
    for (i = 0; i <= 255; i += 2)
        table[i] = (JSAMPLE)i;
    for (i = 1; i <= 255; i += 2)
        table[i] = (JSAMPLE)i;
}
