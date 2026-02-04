#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float mantissa_tab1[17][4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing using a fixed index map
    // We simulate a strided or non-sequential access pattern via an index remapping table.
    // This could model scenarios where data is accessed out of natural order due to constraints.

    const int index_map[14] = {2, 4, 6, 8, 10, 12, 14, 3, 5, 7, 9, 11, 13, 15}; // Even indices first, then odd

    for (int j = 0; j < 14; j++) {
        i = index_map[j]; // Indirect iteration over valid range [2,15]
        int shift_val = (1 << i) - 1;
        mantissa_tab1[i][1] = 1.F / shift_val;
        mantissa_tab1[i][2] = 0.5F / shift_val;
        mantissa_tab1[i][3] = 0.25F / shift_val;
    }
}
