#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double u[1000][1000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Use strided memory access with indirect indexing via pointer arithmetic
    // Simulates non-unit stride access pattern, using a double pointer to traverse u
    double (*up)[1000] = u;
    for (i = 0; i < n; i += 2) {  // Stride of 2 in i dimension
        for (j = 0; j < n; j++) {
            up[i][j] = (double)(i + n - j) / n;
            if (i + 1 < n) {
                up[i+1][j] = (double)((i+1) + n - j) / n;  // Access next row immediately
            }
        }
    }
    // Handle any remaining odd row
    if (n % 2 == 1) {
        i = n - 1;
        for (j = 0; j < n; j++) {
            u[i][j] = (double)(i + n - j) / n;
        }
    }
}
