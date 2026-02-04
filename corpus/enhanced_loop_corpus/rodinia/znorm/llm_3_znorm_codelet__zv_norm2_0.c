#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

typedef struct {
    u_int dim;
    u_int max_dim;
    complex *ve;
} ZVEC;

extern ZVEC *x;
extern int i;
extern int dim;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    sum = 0.0;
    for (i = dim - 1; i >= 0; i--) {
        sum += (x->ve[i].re * x->ve[i].re) + (x->ve[i].im * x->ve[i].im);
    }
}
