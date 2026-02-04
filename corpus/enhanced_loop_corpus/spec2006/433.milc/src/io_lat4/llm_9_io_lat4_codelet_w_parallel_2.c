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
        for (k = 0; k < 3; k++) {
            double temp_real = lbuf[i].e[j][k].real;
            double temp_imag = lbuf[i].e[j][k].imag;
            lbuf[i].e[j][k].real = temp_real * temp_real - temp_imag * temp_imag;
            lbuf[i].e[j][k].imag = 2.0 * temp_real * temp_imag;
        }

}
