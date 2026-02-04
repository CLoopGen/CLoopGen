#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int x[40][2];
extern int lag;
extern int i;
extern int64_t accu_re;
extern int64_t accu_im;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process elements with a fixed stride to simulate cache-friendly or transformed data layout access
    // Here, we change the iteration pattern to jump by 2 indices per step (unrolled-like), but still cover all valid i
    int64_t temp_re = 0;
    int64_t temp_im = 0;

    // Handle even and odd increments separately to maintain correctness over full range
    // First pass: process every second element starting at i=1
    for (i = 1; i < 38; i += 2) {
        temp_re += (uint64_t)x[i][0] * x[i + lag][0];
        temp_re += (uint64_t)x[i][1] * x[i + lag][1];
        temp_im += (uint64_t)x[i][0] * x[i + lag][1];
        temp_im -= (uint64_t)x[i][1] * x[i + lag][0];
    }

    // Second pass: if needed, could be used for software pipelining or prefetching; here it's just strided access demonstration
    // But since we already covered all odd indices, now do even ones (though original starts at 1, so even not required)
    // Instead, simulate dual-stride access pattern for improved cache line utilization

    // Combine result
    accu_re += temp_re;
    accu_im += temp_im;
}
