#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float period;
extern int width;
extern  float *shape;
extern float ppc_gain;
extern float *speech;
extern int len;
extern int i;
extern int j;
extern int center;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced arithmetic complexity and simplified bounds with fixed-point approximation
    // Precompute loop bounds and remove conditional ternary from trip count
    int effective_len = len + ((len >= 0) - (len < 0)) * ((width) >> 1);
    int trip_count = effective_len / width;
    float inv_width = 1.0f / width;
    
    for (i = 1; i < trip_count; i++) {
        // Approximate center using scaled arithmetic (simpler rounding)
        center = (int)(i * period);
        // Simplify inner loop bounds: use symmetric range without complex expressions
        int half_width = width >> 1;
        for (j = -half_width; j < half_width; j++) {
            // Merge pointer increment into assignment
            speech[center + j] += ppc_gain * shape[(i - 1) * width + (j + half_width)];
        }
    }
}
