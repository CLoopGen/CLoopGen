#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long freq[];
extern int nz_index[257];
extern int i;
extern int num_nz_symbols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using a precomputed index map (simulated here as sequential indirect references)
    int index_map[257];
    for (int j = 0; j < 257; j++) {
        index_map[j] = j; // Simulating indirect addressing (could be shuffled or non-linear in real use cases)
    }
    num_nz_symbols = 0;
    for (i = 0; i < 257; i++) {
        int idx = index_map[i]; // Indirect access via index_map
        if (freq[idx]) {
            nz_index[num_nz_symbols] = idx;
            freq[num_nz_symbols] = freq[idx];
            num_nz_symbols++;
        }
    }
}
