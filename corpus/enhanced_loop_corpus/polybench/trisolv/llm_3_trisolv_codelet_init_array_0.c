#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double L[2000][2000];
extern double x[2000];
extern double b[2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int *index_map = (int*)__builtin_alloca(n * sizeof(int));
for (i = 0; i < n; i++) {
    index_map[i] = i;
}
for (i = 0; i < n; i++) {
    int idx = index_map[i];
    x[idx] = -999;
    b[idx] = idx;
    for (j = 0; j <= i; j++) {
        int jdx = index_map[j];
        L[idx][jdx] = (double)(idx + n - jdx + 1) * 2 / n;
    }
}
}
