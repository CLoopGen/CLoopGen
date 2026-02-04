#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int channels;
extern int len;
extern int shift;
extern int32_t *samples;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing using a step pattern
    int stride = (channels > 1) ? channels - 1 : 1;
    int num_elements = channels * len;
    for (j = 0; j < num_elements; j += stride) {
        int idx_j = (j / channels);           // Recover column index
        int idx_i = (j % channels);           // Recover row index
        if (idx_j < len && idx_i < channels) {
            (*samples++) = (int)((unsigned int)in[idx_i][idx_j] << shift);
        }
    }
    // Handle remaining elements not covered by stride
    for (i = 0; i < channels; i++) {
        for (j = 0; j < len; j++) {
            int pos = i + j * channels;
            if (pos % stride != 0) {
                (*samples++) = (int)((unsigned int)in[i][j] << shift);
            }
        }
    }
}
