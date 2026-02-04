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
for (int j = jj; j < jj + S; j++ , v++)
    cache[v] += -((f[i - K - 1] - f[j - K - 1]) * (f[i - K - 1] - f[j - K - 1])) + ((f[i + K] - f[j + K]) * (f[i + K] - f[j + K]));

}
