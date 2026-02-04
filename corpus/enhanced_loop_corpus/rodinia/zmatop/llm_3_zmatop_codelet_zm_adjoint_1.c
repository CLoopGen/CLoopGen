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
extern int i;
extern int j;
extern complex tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory layout simulation using linear indexing
    // Assume that 'base' array is stored consecutively and access via pointer arithmetic
    // We map 2D indices (i,j) to linear offset assuming row-major order
    complex *base = in->base;
    u_int m = in->m;
    for (i = 0; i < m; i++) {
        for (j = 0; j < i; j++) {
            // Convert me[i][j] and me[j][i] to linear offsets
            complex *a = base + i * m + j;
            complex *b = base + j * m + i;

            tmp.re = a->re;
            tmp.im = a->im;

            a->re = b->re;
            a->im = -b->im;

            b->re = tmp.re;
            b->im = -tmp.im;
        }
        // Diagonal element: negate imaginary part
        base[i * m + i].im = -base[i * m + i].im;
    }
}
