#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern  float *X;
extern  int incX;
extern  float *Y;
extern  int incY;
extern float *Ap;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int *index_map = (int*)malloc(N * sizeof(int));
for (int idx = 0; idx < N; idx++) {
    index_map[idx] = idx * incX;
}
for (i = 0; i < N; i++) {
    const double tmp1 = alpha * X[ix];
    const double tmp2 = alpha * Y[iy];
    int jx = ix;
    int jy = iy;
    for (j = i; j < N; j++) {
        int packed_index = (i * (2 * N - i + 1)) / 2 + (j - i);
        int x_offset = index_map[j - i];
        Ap[packed_index] += tmp1 * Y[jy] + tmp2 * X[jx];
        jx += incX;
        jy += incY;
    }
    ix += incX;
    iy += incY;
}
free(index_map);
}
