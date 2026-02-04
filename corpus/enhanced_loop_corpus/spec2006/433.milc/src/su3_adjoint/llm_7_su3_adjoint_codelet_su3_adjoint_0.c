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
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 3; i++) {
        double row_accum[3][2]; // [j][0] = real, [j][1] = imag
        for (j = 0; j < 3; j++) {
            row_accum[j][0] = (a->e[j][i]).real;
            row_accum[j][1] = -(a->e[j][i]).imag;
        }
        for (j = 0; j < 3; j++) {
            (b->e[i][j]).real = row_accum[j][0];
            (b->e[i][j]).imag = row_accum[j][1];
        }
    }
}
