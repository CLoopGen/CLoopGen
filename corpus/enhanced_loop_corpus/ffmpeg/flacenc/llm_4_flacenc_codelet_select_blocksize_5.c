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
for (i = 0; i < 16 && ff_flac_blocksize_table[i] <= target; i++) {
    if (ff_flac_blocksize_table[i] > blocksize) {
        blocksize = ff_flac_blocksize_table[i];
    }
}
}
