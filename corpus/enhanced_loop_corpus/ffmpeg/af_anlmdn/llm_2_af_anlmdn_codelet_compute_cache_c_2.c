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
    // Variant 1: Consecutive memory access with stride simulation via pointer arithmetic
    float *f_i_minus_K_minus_1 = &f[i - K - 1];
    float *f_i_plus_K = &f[i + K];
    float *f_j_base = &f[jj - K - 1];
    float *cache_v = &cache[v];
    
    for (int j = jj; j < jj + S; j++) {
        float diff1 = f_i_minus_K_minus_1[0] - f_j_base[0];
        float diff2 = f_i_plus_K[0] - f_j_base[2*K + 1];
        cache_v[0] += -(diff1 * diff1) + (diff2 * diff2);
        
        f_j_base++;
        cache_v++;
        v++;
    }
}
