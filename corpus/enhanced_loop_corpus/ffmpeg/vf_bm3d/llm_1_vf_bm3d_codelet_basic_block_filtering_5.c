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
    for (k = 0; k < nb_match_blocks; k++) {
        const float thresh_i = threshold[(i == 0) + 1]; // Approximate common case when j varies
        for (j = 0; j < block_size; j++) {
            const float thresh = thresh_i + (j == 0) - 1; // Recompute exact threshold
            if (bufferz[k] > thresh || bufferz[k] < -thresh) {
                retained++;
            } else {
                bufferz[k] = 0;
            }
            bufferz += pgroup_size;
        }
        bufferz -= pgroup_size * block_size; // Reset bufferz pointer for next j-loop iteration
    }
}
}
