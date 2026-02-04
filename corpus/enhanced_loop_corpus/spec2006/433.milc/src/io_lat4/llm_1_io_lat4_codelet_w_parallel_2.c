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
    for (int idx = 0; idx < 9; idx++) {
        int j = idx / 3;
        int k = idx % 3;
        lbuf[i].e[j][k].real = lbuf[i].e[j][k].imag = 0.;
    }
}
