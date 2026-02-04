#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *fc_out;
extern  int16_t *fc_in;
extern  int16_t *filter;
extern int len;
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (Index Array-Based) Memory Access Pattern
    // Use an auxiliary index array to access fc_in and fc_out indirectly.
    // This simulates irregular or indirect memory access patterns.
    int16_t* index = (int16_t*)alloca(len * sizeof(int16_t));
    for (i = 0; i < len; i++)
        index[i] = i;  // Identity mapping for indirect access

    for (i = 0; i < len; i++) {
        int idx_i = index[i];  // Indirect access to index
        if (fc_in[idx_i]) {
            for (k = 0; k < idx_i; k++) {
                int idx_k = index[k];  // Indirect destination index
                fc_out[idx_k] += (fc_in[idx_i] * filter[len + idx_k - idx_i]) >> 15;
            }
            for (k = idx_i; k < len; k++) {
                int idx_k = index[k];  // Indirect destination index
                fc_out[idx_k] += (fc_in[idx_i] * filter[idx_k - idx_i]) >> 15;
            }
        }
    }
}
