#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int r;
extern int s;
extern double (*B)[2000][2000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (r = 0; r < n * n; ++r) {  // Flattened 2D traversal into 1D with adjusted trip count
    int i = r / n;
    int j = r % n;
    A[i][j] = (*B)[i][j];
}
}
