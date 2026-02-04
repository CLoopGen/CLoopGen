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
    double *B_ptr = (double *)B;
    for (i = 0; i < n1; i++) {
        int base_idx = ldb * i;
        double ar = alpha_real;
        double ai = alpha_imag;
        for (j = 0; j < n2; j++) {
            int idx = 2 * (base_idx + j);
            double br = B_ptr[idx];
            double bi = B_ptr[idx + 1];
            // Introduce artificial WAW and WAR dependency by reusing br/bi in a dummy update
            if (j > 0) {
                int prev_idx = 2 * (base_idx + j - 1);
                B_ptr[prev_idx] = B_ptr[prev_idx] + br - B_ptr[idx]; // Artificial RAW and WAW on current br
            }
            B_ptr[idx] = ar * br - ai * bi;
            B_ptr[idx + 1] = ar * bi + ai * br;
        }
    }
}
