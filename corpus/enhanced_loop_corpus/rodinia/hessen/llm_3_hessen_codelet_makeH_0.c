#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

extern MAT *Hout;
extern int i;
extern int j;
extern int limit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access – traverse columns first with a fixed stride across rows
    // Simulate strided access by jumping in increments, processing every other element
    for (i = 1; i < limit; i += 2) {  // Stride of 2 in outer loop
        for (j = 0; j < i - 1; j += 2) {  // Stride of 2 in inner loop
            (Hout)->me[i][j] = 0.;
            // Ensure we don't go out of bounds when accessing adjacent elements
            if (j + 1 < i - 1) {
                (Hout)->me[i][j + 1] = 0.;
            }
        }
        // Handle intermediate row if next i is still within bounds
        if (i + 1 < limit) {
            for (j = 0; j < i; j += 2) {
                (Hout)->me[i + 1][j] = 0.;
                if (j + 1 < i) {
                    (Hout)->me[i + 1][j + 1] = 0.;
                }
            }
        }
    }
}
