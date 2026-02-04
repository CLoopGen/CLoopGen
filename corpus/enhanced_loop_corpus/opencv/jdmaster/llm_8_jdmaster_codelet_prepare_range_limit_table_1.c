#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and doubled trip count
    for (i = 0; i <= 511; i++) {
        int val = (i < 256) ? i : (511 - i);
        table[i % 256] = (JSAMPLE)((val * val + 3 * val + 2) / 4);
    }
}
