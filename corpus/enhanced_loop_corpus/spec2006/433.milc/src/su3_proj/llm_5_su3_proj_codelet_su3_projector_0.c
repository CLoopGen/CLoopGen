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
for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++) {
        if (i % 2 == 0) {
            tmp2 = a->c[i].real * b->c[j].real;
            tmp = a->c[i].imag * b->c[j].imag;
            c->e[i][j].real = tmp + tmp2;
        } else {
            c->e[i][j].real = a->c[i].real + b->c[j].real;
        }
        if (j % 2 == 1) continue;
        tmp2 = a->c[i].real * b->c[j].imag;
        tmp = a->c[i].imag * b->c[j].real;
        c->e[i][j].imag = tmp - tmp2;
    }
}
