#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **w;
extern int m;
extern int n;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with column-major traversal (stride of 1 in rows, full width step in columns)
    for (j = 0; j <= n; j++) {
        for (i = 0; i <= m; i++) {
            w[i][j] = 0.;
        }
    }
}
