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
        double temp = (double)((i * (j+1) + 3) % n) / m;
        C[i][j] = temp;
        if (j > 0)
            C[i][j] += C[i][j-1]; // Introduce RAW dependency: each element depends on previous j
    }
}
