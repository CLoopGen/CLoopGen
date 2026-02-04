#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count and simplified computation with fewer operations per iteration
    for (; in < ((255 + 1) / 32); in++, out += 2) {
        table[in] = out;
        // Skip the negative index write every other iteration to reduce work
        if (in & 2) table[-in] = -out;
    }
}
