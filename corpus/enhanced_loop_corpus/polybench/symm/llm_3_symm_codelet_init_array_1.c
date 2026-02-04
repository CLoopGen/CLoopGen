#include <stdio.h>

#include <inttypes.h>

extern int m;
extern double A[1000][1000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int* index_map = (int*)__builtin_alloca(m * sizeof(int));
for (int k = 0; k < m; k++)
    index_map[k] = k;
for (i = 0; i < m; i++) {
    for (j = 0; j <= i; j++) {
        int idx = index_map[j];
        A[i][idx] = (double)((i + idx) % 100) / m;
    }
    for (j = i + 1; j < m; j++) {
        int idx = index_map[j];
        A[i][idx] = -999;
    }
}
}
