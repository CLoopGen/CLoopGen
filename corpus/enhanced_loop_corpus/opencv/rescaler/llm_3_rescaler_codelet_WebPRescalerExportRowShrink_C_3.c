#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x_out;
extern  int x_out_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int access_pattern[] = {3, 1, 4, 1, 5, 9, 2, 6}; // Example indirect indices
    const int pattern_size = sizeof(access_pattern) / sizeof(access_pattern[0]);
    int idx = 0;
    for (x_out = 0; x_out < x_out_max; ++x_out) {
        idx = access_pattern[x_out % pattern_size]; // Indirect indexing via lookup
        const int frac = idx % 8;
        const int v = frac + 5;
    }
}
