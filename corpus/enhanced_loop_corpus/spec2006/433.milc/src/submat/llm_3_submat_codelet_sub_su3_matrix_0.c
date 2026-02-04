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
    // Variant 2: Memory Access Pattern Modification - Linearized consecutive access using index mapping
    int idx;
    for (idx = 0; idx < 9; idx++) {
        i = idx / 3;
        j = idx % 3;
        {
            (c->e[i][j]).real = (a->e[i][j]).real - (b->e[i][j]).real;
            (c->e[i][j]).imag = (a->e[i][j]).imag - (b->e[i][j]).imag;
        }
        ;
    }
}
