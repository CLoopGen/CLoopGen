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
    for (i = 0; i < lim; i++) {
        if (vec->ve[i].re != 0 || vec->ve[i].im != 0) {
            mat->me[i][col] = vec->ve[i];
        }
    }
}
