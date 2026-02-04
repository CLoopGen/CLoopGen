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
    for (i = 0; i < 257; i += 8) {
        for (int j = 0; j < 8 && (i + j) < 257; j++) {
            int idx = i + j;
            if (freq[idx]) {
                nz_index[num_nz_symbols] = idx;
                freq[num_nz_symbols] = freq[idx];
                num_nz_symbols++;
            }
        }
    }
}
