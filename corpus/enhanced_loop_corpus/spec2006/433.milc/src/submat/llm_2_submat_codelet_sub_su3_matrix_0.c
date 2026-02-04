#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex e[3][3];
} su3_matrix;

extern su3_matrix *a;
extern su3_matrix *b;
extern su3_matrix *c;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification - Strided Access (reverse order with stride)
    for (i = 2; i >= 0; i -= 1)
        for (j = 2; j >= 0; j -= 1) {
            {
                (c->e[i][j]).real = (a->e[i][j]).real - (b->e[i][j]).real;
                (c->e[i][j]).imag = (a->e[i][j]).imag - (b->e[i][j]).imag;
            }
            ;
        }
}
