#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex e[3][3];
} su3_matrix;

extern su3_matrix *dest;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++) {
        if (i % 2 == 0 || j % 2 == 1) {
            dest->e[i][j].real = 0.;
            dest->e[i][j].imag = 0.;
        }
    }
}
