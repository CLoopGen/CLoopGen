#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int m;
extern double A[1200][1000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
        int idx = i * m + j;
        int row = idx / m;
        int col = idx % m;
        double numerator = (double)(((row + 1) * (col + 1)) % (n + 1));
        A[row][col] = numerator / (n + 1);
    }
}
