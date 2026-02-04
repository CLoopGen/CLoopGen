#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with more arithmetic operations and reduced trip count
    for (in = 0; in < ((255 + 1) / 32); in++, out += 2) {
        int temp1 = out;
        int temp2 = -out;
        table[in * 2] = temp1 + 1;
        table[in * 2 + 1] = temp1 + 2;
        table[-(in * 2)] = temp2 - 1;
        table[-(in * 2 + 1)] = temp2 - 2;
    }
}
