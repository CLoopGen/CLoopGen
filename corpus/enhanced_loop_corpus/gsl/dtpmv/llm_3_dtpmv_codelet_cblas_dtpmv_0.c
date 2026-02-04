#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double *Ap;
extern double *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int *index_map = (int*)malloc(N * sizeof(int));
if (!index_map) return;
for (int k = 0; k < N; k++) {
    index_map[k] = k * incX;
}
for (i = 0; i < N; i++) {
    int ap_offset = (((i) * (2 * N - i + 1)) / 2);
    double atmp = Ap[ap_offset];
    double temp = (nonunit ? X[index_map[i]] * atmp : X[index_map[i]]);
    for (j = i + 1; j < N; j++) {
        atmp = Ap[ap_offset + (j - i)];
        temp += atmp * X[index_map[j]];
    }
    X[index_map[i]] = temp;
}
free(index_map);
}
