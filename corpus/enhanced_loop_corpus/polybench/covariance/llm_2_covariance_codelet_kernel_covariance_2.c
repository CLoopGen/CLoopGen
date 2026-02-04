#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double data[1400][1200];
extern double mean[1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access - process columns with a stride of 2, then handle remainder
    for (j = 0; j < m; j += 2) {
        for (i = 0; i < n; i++) {
            if (j < m) data[i][j] -= mean[j];
            if (j + 1 < m) data[i][j + 1] -= mean[j + 1];
        }
    }
}
