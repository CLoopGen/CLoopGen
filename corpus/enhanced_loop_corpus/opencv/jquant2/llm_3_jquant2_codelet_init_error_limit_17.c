#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward and backward array access using offset indexing
    int base_in = 0;
    int base_out = out;
    for (in = 0; in < ((255 + 1) / 16); in++, out++) {
        int idx = base_in + in;
        table[idx] = base_out + in;
        table[255 - idx] = -(base_out + in);
    }
}
