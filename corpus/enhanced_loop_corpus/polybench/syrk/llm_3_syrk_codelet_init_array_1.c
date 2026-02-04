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
        // Strided access with step 2: process 2x2 block elements with stride
        C[i][j] = (double)((i * j + 2) % m) / m;
        if (j + 1 < n)
            C[i][j+1] = (double)((i * (j+1) + 2) % m) / m;
        if (i + 1 < n) {
            C[i+1][j] = (double)(((i+1) * j + 2) % m) / m;
            if (j + 1 < n)
                C[i+1][j+1] = (double)(((i+1) * (j+1) + 2) % m) / m;
        }
    }
}
