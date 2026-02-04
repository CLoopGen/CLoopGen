#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count via step increment
    for (i = 128; i < 2 * (255 + 1); i += 2) {
        table[i] = 255;
        table[i + 1] = 255;
    }
}
