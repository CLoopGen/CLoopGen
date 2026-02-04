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
for (i = 0; i < block_size * block_size; i++) {
    int local_retained = 0;
    int idx_i = i / block_size;
    int idx_j = i % block_size;
    const float thresh = threshold[(idx_j == 0) + (idx_i == 0) + (0 == 0)];
    for (k = 0; k < nb_match_blocks; k++) {
        if (bufferz[k] > thresh || bufferz[k] < -thresh) {
            local_retained++;
        }
    }
    retained += local_retained;
    bufferz += pgroup_size;
}
}
