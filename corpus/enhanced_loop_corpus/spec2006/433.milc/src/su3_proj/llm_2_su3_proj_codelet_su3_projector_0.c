#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex c[3];
} su3_vector;

typedef struct {
    complex e[3][3];
} su3_matrix;

extern su3_vector *a;
extern su3_vector *b;
extern su3_matrix *c;
extern int i;
extern int j;
extern double tmp;
extern double tmp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification using strided access with reversed index order (j outer, i inner)
    for (j = 0; j < 3; j++)
        for (i = 0; i < 3; i++) {
            tmp2 = a->c[i].real * b->c[j].real;
            tmp = a->c[i].imag * b->c[j].imag;
            c->e[i][j].real = tmp + tmp2;
            tmp2 = a->c[i].real * b->c[j].imag;
            tmp = a->c[i].imag * b->c[j].real;
            c->e[i][j].imag = tmp - tmp2;
        }
}
