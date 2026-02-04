#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *B;
extern  int ldb;
extern int i;
extern int j;
extern int n1;
extern int n2;
extern  double alpha_real;
extern  double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Memory Access Pattern via Linear Indexing
    // Flatten the 2D access into a single loop with consecutive memory traversal
    const ptrdiff_t total_elements = n1 * n2;
    for (ptrdiff_t idx = 0; idx < total_elements; idx++) {
        const int i = idx / n2;
        const int j = idx % n2;
        if (i >= n1) continue; // Safety bound (redundant but clear)
        const ptrdiff_t base_offset = 2 * (ldb * i + j);
        const double Bij_real = ((double *)B)[base_offset];
        const double Bij_imag = ((double *)B)[base_offset + 1];
        ((double *)B)[base_offset]     = alpha_real * Bij_real - alpha_imag * Bij_imag;
        ((double *)B)[base_offset + 1] = alpha_real * Bij_imag + alpha_imag * Bij_real;
    }
}
