#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    for (i = 0; i <= 127; i++) {
        int doubled = i * 2;
        table[doubled] = (JSAMPLE)doubled;
        table[doubled + 1] = (JSAMPLE)(doubled + 1);
    }
}
