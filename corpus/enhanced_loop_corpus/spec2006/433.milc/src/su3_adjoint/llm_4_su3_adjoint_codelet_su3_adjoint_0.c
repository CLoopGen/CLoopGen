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
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            if (!(i == 1 && j == 1)) {
                (b->e[i][j]).real = (a->e[j][i]).real;
                (b->e[i][j]).imag = -(a->e[j][i]).imag;
            } else {
                continue;
            }
        }
}
