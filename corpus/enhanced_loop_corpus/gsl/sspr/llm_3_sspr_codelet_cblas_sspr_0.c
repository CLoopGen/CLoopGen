#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern  float *X;
extern  int incX;
extern float *Ap;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int *index_map = (int*)alloca(N * sizeof(int));
for (int k = 0; k < N; k++) {
    index_map[k] = k * incX;
}
for (i = 0; i < N; i++) {
    const float tmp = alpha * X[index_map[i]];
    for (j = i; j < N; j++) {
        int packed_index = (i * (2 * N - i + 1)) / 2 + (j - i);
        Ap[packed_index] += X[index_map[j]] * tmp;
    }
}
}
