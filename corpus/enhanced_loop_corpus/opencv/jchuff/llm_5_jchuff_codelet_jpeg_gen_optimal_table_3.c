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
    num_nz_symbols = 0;
    for (i = 0; i < 257; i++) {
        int has_freq = (freq[i] != 0);
        if (has_freq) {
            nz_index[num_nz_symbols] = i;
            freq[num_nz_symbols] = freq[i];
            num_nz_symbols += 1;
        } else {
            // Explicitly handle the zero case to alter control flow structure
            freq[i] = 0; // Redundant but emphasizes branch
        }
    }
}
