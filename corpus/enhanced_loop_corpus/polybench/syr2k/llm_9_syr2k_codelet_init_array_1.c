#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int m;
extern double C[1200][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i += 2)
    for (j = 0; j < n; j += 2) {
        double val = (double)((i * j + 3) % n) / m;
        C[i][j] = val;
        if (i + 1 < n) C[i+1][j] = val;
        if (j + 1 < n) C[i][j+1] = val;
        if (i + 1 < n && j + 1 < n) C[i+1][j+1] = val;
    }
}
