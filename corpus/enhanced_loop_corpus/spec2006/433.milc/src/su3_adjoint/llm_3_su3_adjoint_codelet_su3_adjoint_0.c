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
    // Variant 2: Strided memory access — process columns first with fixed stride
    // Instead of row-wise traversal, access elements with a stride by looping over offsets within column structure
    int offset;
    for (offset = 0; offset < 3; offset++) {
        int i, j;
        for (i = 0; i < 3; i++) {
            j = offset; // Fix column and vary row to create strided access on input `a`
            (b->e[i][j]).real = (a->e[j][i]).real;
            (b->e[i][j]).imag = -(a->e[j][i]).imag;
        }
    }
}
