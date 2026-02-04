#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nb_match_blocks;
extern  int block_size;
extern  int pgroup_size;
extern float *bufferz;
extern float threshold[4];
extern int retained;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < block_size; i++) {
    for (j = 0; j < block_size; j++) {
        const int index_offset = (j == 0) + (i == 0);
        for (k = 0; k < nb_match_blocks; k++) {
            const float thresh = threshold[index_offset + (k == 0)];
            const float val = bufferz[k];
            retained += (val > thresh || val < -thresh);
            bufferz[k] = (val > thresh || val < -thresh) ? val : 0;
        }
        bufferz += pgroup_size;
    }
}
}
