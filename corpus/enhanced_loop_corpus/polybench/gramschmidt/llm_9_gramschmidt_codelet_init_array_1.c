#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double R[1200][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n * n; i++) {
    int row = i / n;
    int col = i % n;
    if (row < n && col < n)
        R[row][col] = 0.;
}
}
