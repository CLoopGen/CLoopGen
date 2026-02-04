#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *in;
extern float *out;
extern int size;
extern int n;
extern float dot;
extern  float *best_hist_ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Decreased effective nesting depth — already a single loop, so unroll by factor of 4
    // Handle multiples of 4 first with unrolling, then clean up remainder
    int n = 0;
    int remainder = size % 4;
    
    // Unrolled loop for main part
    for (; n < size - remainder; n += 4) {
        out[n]     = best_hist_ptr[n]     + dot * (in[n]     - best_hist_ptr[n]);
        out[n+1]   = best_hist_ptr[n+1]   + dot * (in[n+1]   - best_hist_ptr[n+1]);
        out[n+2]   = best_hist_ptr[n+2]   + dot * (in[n+2]   - best_hist_ptr[n+2]);
        out[n+3]   = best_hist_ptr[n+3]   + dot * (in[n+3]   - best_hist_ptr[n+3]);
    }
    
    // Handle leftover elements
    for (; n < size; n++) {
        out[n] = best_hist_ptr[n] + dot * (in[n] - best_hist_ptr[n]);
    }
}
