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
        for (k = 0; k < nb_match_blocks; k++) {
            const float thresh = threshold[(j == 0) + (i == 0) + (k == 0)];
            if (!(bufferz[k] > thresh || bufferz[k] < -thresh)) {
                bufferz[k] = 0;
            } else {
                retained++;
            }
        }
        bufferz += pgroup_size;
    }
}
}
