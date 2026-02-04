#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int hits[33];
extern int i;
extern int j;
extern int selected[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index remapping
    // Use a fixed indirect lookup table to reorder access to hits array
    int order[33];
    for (int k = 0; k < 33; k++)
        order[k] = (7 * k + 19) % 33; // Generate pseudo-random permutation using linear congruential map

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 33; j++) {
            int idx = order[j]; // Indirect access through remapped index
            if (hits[idx] > hits[selected[i]])
                selected[i] = idx;
        }
        hits[selected[i]] = 0;
    }
}
