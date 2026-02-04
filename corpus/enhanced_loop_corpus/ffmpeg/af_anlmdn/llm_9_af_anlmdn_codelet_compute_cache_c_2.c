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
for (int j = jj; j < jj + S; j += 2, v += 2) {
    if (j + 1 >= jj + S) break;
    float term1_prev = (f[i - K - 1] - f[j - K - 1]) * (f[i - K - 1] - f[j - K - 1]);
    float term2_prev = (f[i + K] - f[j + K]) * (f[i + K] - f[j + K]);
    float term1_next = (f[i - K - 1] - f[j + 1 - K - 1]) * (f[i - K - 1] - f[j + 1 - K - 1]);
    float term2_next = (f[i + K] - f[j + 1 + K]) * (f[i + K] - f[j + 1 + K]);
    cache[v] += -term1_prev + term2_prev;
    cache[v + 1] += -term1_next + term2_next;
}
}
