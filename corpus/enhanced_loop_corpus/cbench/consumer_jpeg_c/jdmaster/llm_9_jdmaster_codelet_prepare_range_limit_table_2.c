#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Decreased trip count with more complex index computation but same effective behavior
    int limit = (255 + 1) + 64;
    for (i = 128; i < limit; i++) {
        table[2 * i - 128] = 255;
    }
}
