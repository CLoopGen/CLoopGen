#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const int32_t ff_flac_blocksize_table[16];
extern int i;
extern int target;
extern int blocksize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with reverse traversal (stride of -1)
    for (i = 15; i >= 0; i--) {
        if (target >= ff_flac_blocksize_table[i] && ff_flac_blocksize_table[i] > blocksize) {
            blocksize = ff_flac_blocksize_table[i];
        }
    }
}
