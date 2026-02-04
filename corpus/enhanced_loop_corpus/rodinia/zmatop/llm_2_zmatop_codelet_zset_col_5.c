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

typedef struct {
    u_int dim;
    u_int max_dim;
    complex *ve;
} ZVEC;

extern ZMAT *mat;
extern ZVEC *vec;
extern int col;
extern u_int i;
extern u_int lim;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D matrix access into a 1D pattern
    // Assuming column-major layout, we access elements at regular stride (max_n = number of columns)
    complex *base = mat->base;
    u_int max_n = mat->max_n;
    for (i = 0; i < lim; i++) {
        base[i * max_n + col] = vec->ve[i];
    }
}
