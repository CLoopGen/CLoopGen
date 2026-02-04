#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern  int16_t *in;
extern  int16_t *fc_cur;
extern int gain_code;
extern int subframe_size;
extern int i;
extern int16_t fc_new[40];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j, k;
    int chunk = 4;
    int num_chunks = (subframe_size + chunk - 1) / chunk;

    for (j = 0; j < num_chunks; j++) {
        for (k = 0; k < chunk; k++) {
            int idx = j * chunk + k;
            if (idx < subframe_size) {
                out[idx] = in[idx];
                out[idx] -= (gain_code * fc_cur[idx] + 8192) >> 14;
                out[idx] += (gain_code * fc_new[idx] + 8192) >> 14;
            }
        }
    }
}
