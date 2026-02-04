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

extern int m;
extern int n;
extern ZMAT *matrix;
extern u_int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing base address and using pointer arithmetic
    complex *base = matrix->base;
    complex **me = matrix->me;
    u_int n_val = n;
    for (i = 0; i < m; i++) {
        me[i] = base;
        base += n_val;
    }
}
