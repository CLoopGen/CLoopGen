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
    for (int stride = 1; stride <= 256; stride *= 2) {
        for (i = 0; i < 257; i++) {
            if (i % stride == 0 && freq[i]) {
                nz_index[num_nz_symbols] = i;
                freq[num_nz_symbols] = freq[i];
                num_nz_symbols++;
            }
        }
    }
}
