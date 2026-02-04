#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  void *A;
extern  int lda;
extern  void *X;
extern  int incX;
extern void *Y;
extern  int incY;
extern int i;
extern int j;
extern int lenX;
extern int lenY;
extern  double alpha_real;
extern  double alpha_imag;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < lenY; i++) {
    double dotR = 0.;
    double dotI = 0.;
    int ix = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX)));
    for (j = 0; j < lenX; j++) {
        const double x_real = (((const double *)X)[2 * (ix)]);
        const double x_imag = (((const double *)X)[2 * (ix) + 1]);
        const double A_real = (((const double *)A)[2 * (lda * i + j)]);
        const double A_imag = (((const double *)A)[2 * (lda * i + j) + 1]);
        // Introduce artificial dependency: make current computation depend on previous dotR/dotI
        // This creates a WAW and RAW hazard intentionally, forcing sequential execution
        double tempR = dotR + A_real * x_real - (-A_imag) * x_imag;
        double tempI = dotI + A_real * x_imag + (-A_imag) * x_real;
        dotR = tempR;
        dotI = tempI;
        ix += incX;
    }
    // Update Y only after full accumulation to preserve semantics
    (((double *)Y)[2 * (iy)]) += alpha_real * dotR - alpha_imag * dotI;
    (((double *)Y)[2 * (iy) + 1]) += alpha_real * dotI + alpha_imag * dotR;
    iy += incY;
}
}
