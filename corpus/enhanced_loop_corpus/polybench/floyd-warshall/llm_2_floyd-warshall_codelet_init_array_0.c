#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int path[2800][2800];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing path[i][j] in row-major order, we access with a stride of 2
    // by iterating j in steps of 2 and handling even and odd indices separately.
    // We also unroll the inner loop partially to maintain coverage.
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j += 2) {
            int idx = i * n + j;
            path[i][j] = i * j % 7 + 1;
            if ((i + j) % 13 == 0 || (i + j) % 7 == 0 || (i + j) % 11 == 0)
                path[i][j] = 999;
            if (j + 1 < n) {
                path[i][j+1] = i * (j+1) % 7 + 1;
                if ((i + j + 1) % 13 == 0 || (i + j + 1) % 7 == 0 || (i + j + 1) % 11 == 0)
                    path[i][j+1] = 999;
            }
        }
    }
}
