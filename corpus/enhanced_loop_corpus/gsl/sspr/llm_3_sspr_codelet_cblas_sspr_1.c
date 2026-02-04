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
int *index_map = (int*)malloc(N * sizeof(int));
for (int idx = 0; idx < N; idx++) {
    index_map[idx] = idx * incX;
}
for (i = 0; i < N; i++) {
    const float tmp = alpha * X[ix];
    for (j = 0; j <= i; j++) {
        int phys_j = (incX > 0) ? index_map[j] : index_map[N - 1 - j];
        Ap[(i * (i + 1)) / 2 + j] += X[phys_j] * tmp;
    }
    ix += incX;
}
free(index_map);
}
