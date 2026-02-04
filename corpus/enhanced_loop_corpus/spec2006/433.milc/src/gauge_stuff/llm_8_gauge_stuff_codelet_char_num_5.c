#include <stdio.h>

#include <inttypes.h>

extern int length;
extern int j;
extern int bdig[6];
extern int old;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations
    // and reduced trip count by stepping down in increments of 2.
    for (j = length - 2; j >= 0; j -= 2) {
        old = old * 100 + bdig[j] * 10;
        if (j > 0) {
            old += bdig[j-1];
        }
    }
}
