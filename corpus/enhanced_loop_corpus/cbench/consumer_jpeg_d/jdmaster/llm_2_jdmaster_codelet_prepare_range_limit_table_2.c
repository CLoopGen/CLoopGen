#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive write with reverse traversal (backward access pattern)
    for (i = 2 * (255 + 1) - 1; i >= 128; i--)
        table[i] = 255;
}
