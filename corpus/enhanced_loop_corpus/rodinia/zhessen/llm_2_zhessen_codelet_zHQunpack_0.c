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

extern ZMAT *H;
extern int i;
extern int j;
extern int limit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification - Consecutive access via pointer arithmetic
    // Instead of accessing H->me[i][j], we precompute row pointers and traverse elements consecutively
    for (i = 1; i < limit; i++) {
        complex *row = H->me[i];
        for (j = 0; j < i - 1; j++) {
            row[j].re = 0.;
            row[j].im = 0.;
        }
    }
}
