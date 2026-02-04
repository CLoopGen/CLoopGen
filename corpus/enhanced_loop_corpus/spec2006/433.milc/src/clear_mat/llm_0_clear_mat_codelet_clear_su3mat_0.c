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
int idx;
for (idx = 0; idx < 9; idx++) {
    int i = idx / 3;
    int j = idx % 3;
    dest->e[i][j].real = dest->e[i][j].imag = 0.;
}
}
