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
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            int idx = i * 3 + j;
            ((double*)c)[idx * 2 + 0] = ((double*)a)[idx * 2 + 0] + ((double*)b)[idx * 2 + 0];
            ((double*)c)[idx * 2 + 1] = ((double*)a)[idx * 2 + 1] + ((double*)b)[idx * 2 + 1];
        }
}
