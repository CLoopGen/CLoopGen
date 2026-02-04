#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *y;
extern float mem[2];
extern  float *x;
extern  float *b;
extern  float *a;
extern int N;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev_mem0 = mem[0];
    float prev_mem1 = mem[1];
    for (int i = 0; i < N; i++) {
        float xi = x[i];
        float yi = xi + prev_mem0;
        float next_mem0 = prev_mem1 + (b[0] * xi - a[0] * yi);
        float next_mem1 = b[1] * xi - a[1] * yi;
        y[i] = yi;
        // Update state for next iteration (loop-carried dependency preserved)
        prev_mem0 = next_mem0;
        prev_mem1 = next_mem1;
    }
    // Final update to global mem only if needed by external semantics
    // Otherwise, we could eliminate write-back if only y[] is required
    mem[0] = prev_mem0;
    mem[1] = prev_mem1;
}
