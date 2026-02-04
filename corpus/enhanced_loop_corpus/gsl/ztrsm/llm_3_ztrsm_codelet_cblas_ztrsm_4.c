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
    // Variant 2: Strided memory access — traverse columns first (j-loop outer), improving spatial locality along column dimension
    for (j = 0; j < n2; j++) {
        for (i = 0; i < n1; i++) {
            const int idx = 2 * (ldb * i + j);
            const double Bij_real = ((double*)B)[idx];
            const double Bij_imag = ((double*)B)[idx + 1];
            ((double*)B)[idx]     = alpha_real * Bij_real - alpha_imag * Bij_imag;
            ((double*)B)[idx + 1] = alpha_real * Bij_imag + alpha_imag * Bij_real;
        }
    }
}
