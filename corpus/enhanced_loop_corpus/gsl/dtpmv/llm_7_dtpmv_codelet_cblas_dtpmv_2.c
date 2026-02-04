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
double *temp_arr = (double*)alloca(N * sizeof(double));
int *index_map = (int*)alloca(N * sizeof(int));
for (int idx = 0; idx < N; idx++) {
    index_map[idx] = (incX > 0 ? idx : (N - 1 - idx));
}
for (i = 0; i < N; i++) {
    double atmp = Ap[((((i) * (2 * N - i)) / 2))];
    double temp = (nonunit ? X[index_map[i]] * atmp : X[index_map[i]]);
    for (j = i + 1; j < N; j++) {
        int pos = ((((j) * (2 * N - j - 1)) / 2) + i);
        atmp = Ap[pos];
        temp += atmp * X[index_map[j]];
    }
    temp_arr[i] = temp;
}
for (i = N - 1; i >= 0; i--) {
    X[ix] = temp_arr[N - 1 - i];
    ix -= incX;
}
}
