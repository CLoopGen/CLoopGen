#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2, unrolling to write two elements per iteration
    for (i = 0; i <= 254; i += 2) {
        table[i] = (JSAMPLE)i;
        table[i + 1] = (JSAMPLE)(i + 1);
    }
    // Handle last element if needed (though 255 is covered by i+1 when i=254)
    if (i == 255) {
        table[i] = (JSAMPLE)i;
    }
}
