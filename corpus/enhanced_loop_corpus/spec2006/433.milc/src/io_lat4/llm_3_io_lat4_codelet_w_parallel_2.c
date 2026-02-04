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
    // Variant 2: Strided access pattern - traverse across all i indices first for each fixed j,k component
    // This creates a stride in memory corresponding to the size of the su3_matrix structure
    for (int j = 0; j < 3; j++)
        for (int k = 0; k < 3; k++)
            for (int i = 0; i < 4096; i++) {
                lbuf[i].e[j][k].real = 0.0;
                lbuf[i].e[j][k].imag = 0.0;
            }
}
