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
    int local_count = num_nz_symbols;
    for (i = 0; i < 257; i++) {
        long f = freq[i];
        if (f) {
            nz_index[local_count] = i;
            freq[local_count] = f;
            local_count++;
        }
    }
    num_nz_symbols = local_count;
}
