#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Introduce strided memory access by processing every second element in both dimensions
    for (i = 0; i < n; i += 2)
        for (j = 0; j < n; j += 2)
            A[i][j] = ((double)i * (j + 2) + 2) / n;
}
