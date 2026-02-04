#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive bidirectional write using offset-based indexing
    int base_in = in;
    int base_out = out;
    for (int i = 0; i < ((255 + 1) / 16); i++) {
        table[base_in + i] = base_out + i;
        table[base_in - i] = -(base_out + i);
    }
    in += ((255 + 1) / 16);
    out += ((255 + 1) / 16);
}
