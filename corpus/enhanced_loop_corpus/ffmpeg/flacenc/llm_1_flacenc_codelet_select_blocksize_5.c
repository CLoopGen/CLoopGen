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
    for (i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
            int idx = i * 4 + k;
            if (idx < 16) {
                if (target >= ff_flac_blocksize_table[idx] && ff_flac_blocksize_table[idx] > blocksize) {
                    blocksize = ff_flac_blocksize_table[idx];
                }
            }
        }
    }
}
