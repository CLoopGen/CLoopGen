#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double A[2100][1900];
extern double r[2100];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int* index_map = (int*)__builtin_alloca(n * sizeof(int));
for (i = 0; i < n; i++) {
    index_map[i] = (i * 7) % n;  // Indirect access pattern via permutation
}
for (i = 0; i < n; i++) {
    int idx = index_map[i];
    r[idx] = (double)(i % n) / n;
    for (j = 0; j < m; j++) {
        int col_idx = (j * 5) % m;  // Strided column access
        A[idx][col_idx] = (double)(i * (j + 1) % n) / n;
    }
}
}
