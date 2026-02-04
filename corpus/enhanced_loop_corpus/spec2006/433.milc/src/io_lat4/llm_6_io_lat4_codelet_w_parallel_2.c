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



void loop() {
    // Variant 1: Introduce loop-carried dependence by accumulating values across iterations
    // This creates a WAW (Write-After-Write) and RAW (Read-After-Write) dependency on a running sum
    // The inner loops remain the same, but now each iteration depends on the previous i

    double acc_real = 0.0;
    double acc_imag = 0.0;

    for (i = 0; i < 4096; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                // Accumulate from previous state before zeroing
                lbuf[i].e[j][k].real = acc_real;
                lbuf[i].e[j][k].imag = acc_imag;
                // Update accumulator with current cell's contribution (before zeroing in next step conceptually)
                acc_real += lbuf[i].e[j][k].real;
                acc_imag += lbuf[i].e[j][k].imag;
                // Now zero it as in original
                lbuf[i].e[j][k].real = 0.0;
                lbuf[i].e[j][k].imag = 0.0;
            }
        }
    }
}
