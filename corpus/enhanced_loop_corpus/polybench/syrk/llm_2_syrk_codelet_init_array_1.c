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
    for (j = 0; j < n; j++)
        C[j][i] = (double)((i * j + 2) % m) / m;  // Transposed access: column-major order for better spatial locality in destination
}
