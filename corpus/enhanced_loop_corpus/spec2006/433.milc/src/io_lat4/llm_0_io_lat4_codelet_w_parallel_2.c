#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex e[3][3];
} su3_matrix;

extern su3_matrix *lbuf;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4096; i++)
    for (j = 0; j < 3; j++)
        for (k = 0; k < 3; k++)
            for (int m = 0; m < 1; m++) {
                lbuf[i].e[j][k].real = lbuf[i].e[j][k].imag = 0.;
            }
}
