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

ZMAT *A;
int new_m;
int new_n;
u_int i;

void init_vars() {
    new_m = 8192;
    new_n = 4096;
    
    A = (ZMAT*)calloc(1, sizeof(ZMAT));
    A->m = new_m;
    A->n = new_n;
    A->max_m = new_m;
    A->max_n = new_n;
    A->max_size = new_m * new_n;
    
    A->base = (complex*)calloc(A->max_size, sizeof(complex));
    A->me = (complex**)calloc(A->max_m, sizeof(complex*));
}