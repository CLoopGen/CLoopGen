#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int m;
extern double C[1200][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
        int idx = i * n + j;
        int row = idx / n;
        int col = idx % n;
        C[row][col] = (double)(((row + 1) * (col + 1) + 3) % m) / m;
    }
}
