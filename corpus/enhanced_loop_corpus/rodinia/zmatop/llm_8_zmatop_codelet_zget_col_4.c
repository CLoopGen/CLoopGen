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

extern int col;
extern ZMAT *mat;
extern ZVEC *vec;
extern u_int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u_int step = 2;
    for (i = 0; i < mat->m; i += step) {
        if (i < mat->m) vec->ve[i] = mat->me[i][col];
        if (i + 1 < mat->m) vec->ve[i + 1] = mat->me[i + 1][col];
    }
}
