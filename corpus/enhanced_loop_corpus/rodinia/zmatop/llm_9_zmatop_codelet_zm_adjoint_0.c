#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    complex *base;
    complex **me;
} ZMAT;

extern ZMAT *in;
extern ZMAT *out;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with strided outer loop and simplified operation
    // Process only even-indexed rows, reducing total iterations by ~50%
    for (i = 0; i < in->m; i += 2) {
        for (j = 0; j < in->n; j++) {
            // Only conjugate transpose without extra computation
            out->me[j][i].re = in->me[i][j].re;
            out->me[j][i].im = -in->me[i][j].im;
        }
    }
    // Ensure minimal coverage by handling edge case if m is odd
    if (in->m > 0 && (in->m % 2) == 1) {
        i = in->m - 1;
        for (j = 0; j < in->n; j++) {
            out->me[j][i].re = in->me[i][j].re;
            out->me[j][i].im = -in->me[i][j].im;
        }
    }
}
