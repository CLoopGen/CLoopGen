#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double (*matrix)[3];
extern double *r;
extern  int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element in reverse, with bounds check)
    for (i = (n - 2) & ~1; i >= 0; i -= 2) {
        if (i + 1 < n) {
            r[i] = r[i] - matrix[i][2] * r[i + 1];
        }
        if (i >= 1) {
            r[i - 1] = r[i - 1] - matrix[i - 1][2] * r[i];
        }
    }
}
