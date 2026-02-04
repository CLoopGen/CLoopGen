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

extern ZVEC *x1;
extern ZVEC *x2;
extern ZVEC *out;
extern int i;
extern double t_re;
extern double t_im;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc(x1->dim * sizeof(int));
    for (int j = 0; j < x1->dim; j++) {
        indices[j] = j;
    }
    // Simulate arbitrary but valid access order (reverse in this case)
    for (i = 0; i < x1->dim; i++) {
        int idx = indices[x1->dim - 1 - i]; // reverse access
        t_re = x1->ve[idx].re * x2->ve[idx].re - x1->ve[idx].im * x2->ve[idx].im;
        t_im = x1->ve[idx].re * x2->ve[idx].im + x1->ve[idx].im * x2->ve[idx].re;
        out->ve[idx].re = t_re;
        out->ve[idx].im = t_im;
    }
    free(indices);
}
