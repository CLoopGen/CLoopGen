#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *cache;
extern  float *f;
extern ptrdiff_t S;
extern ptrdiff_t K;
extern ptrdiff_t i;
extern ptrdiff_t jj;
extern int v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process every 2nd element in a widened effective range
    ptrdiff_t stride = 2;
    ptrdiff_t adjusted_S = S / stride;

    for (int step = 0; step < adjusted_S; step++) {
        int j = jj + step * stride;
        ptrdiff_t index1_i = i - K - 1;
        ptrdiff_t index1_j = j - K - 1;
        ptrdiff_t index2_i = i + K;
        ptrdiff_t index2_j = j + K;

        cache[v] += -((f[index1_i] - f[index1_j]) * (f[index1_i] - f[index1_j])) 
                   + ((f[index2_i] - f[index2_j]) * (f[index2_i] - f[index2_j]));

        v++;
    }
}
