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
            int row = idx / 3;
            int col = idx % 3;
            (c->e[row][col]).real = (a->e[row][col]).real - (b->e[row][col]).real;
            (c->e[row][col]).imag = (a->e[row][col]).imag - (b->e[row][col]).imag;
        }
}
