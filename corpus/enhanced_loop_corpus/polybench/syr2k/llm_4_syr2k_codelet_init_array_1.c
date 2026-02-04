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
        if ((i * j + 3) % m == 0) {
            C[i][j] = 0.0;
            continue;
        }
        C[i][j] = (double)((i * j + 3) % n) / m;
    }
}
