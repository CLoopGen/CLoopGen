#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t dwtcoef;

int x;
dwtcoef *synthl;
ptrdiff_t synth_width;

void init_vars() {
    synth_width = 16777216 / sizeof(dwtcoef);  // ~64 MB of data (adjust for ~0.01 sec runtime)
    
    // Allocate extra space to prevent out-of-bounds access
    ptrdiff_t total_size = synth_width * 3;  // Need indices from -synth_width to +synth_width
    synthl = (dwtcoef*)aligned_alloc(32, total_size * sizeof(dwtcoef));
    
    if (!synthl) {
        exit(1);
    }
    
    // Initialize all elements to zero
    for (ptrdiff_t i = 0; i < total_size; i++) {
        synthl[i] = 0;
    }
    
    // Adjust base pointer so that valid index range [0, synth_width-1] is centered
    // Original loop uses: x - synth_width, x, x + synth_width
    // So we want the actual array to start at offset synth_width in allocated memory
    dwtcoef* base = synthl;
    synthl = &base[synth_width];  // Now synthl[0] points to middle segment
}
