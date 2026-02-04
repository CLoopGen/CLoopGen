#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern  int16_t *filter_coeffs;
extern  int16_t *in;
extern int subframe_size;
extern int i;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed input indexing
    // Instead of accessing in[n - i - 1], we precompute a reversed view or access pattern
    // Here, we simulate consecutive backward traversal by using a base pointer offset
    for (n = subframe_size - 1; n >= 0; n--) {
        int sum = 2048;
        const int16_t *in_ptr = &in[n - 1]; // Base pointer for this iteration
        for (i = 0; i < 10; i++) {
            sum += filter_coeffs[i] * in_ptr[-i]; // Consecutive backward access from n-1
        }
        out[n] = in[n] + (sum >> 12);
    }
}
