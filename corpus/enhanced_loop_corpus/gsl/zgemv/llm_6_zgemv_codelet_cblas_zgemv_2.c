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
        // Introduce temporary accumulators to create local WAW dependency and break direct accumulation
        double temp_dotR = dotR + (A_real * x_real - A_imag * x_imag);
        double temp_dotI = dotI + (A_real * x_imag + A_imag * x_real);
        dotR = temp_dotR;
        dotI = temp_dotI;
        ix += incX;
    }
    // Add artificial dependency on previous Y value to introduce RAW dependency
    double y_temp_real = (((double *)Y)[2 * (iy)]);
    double y_temp_imag = (((double *)Y)[2 * (iy) + 1]);
    (((double *)Y)[2 * (iy)]) = y_temp_real + alpha_real * dotR - alpha_imag * dotI;
    (((double *)Y)[2 * (iy) + 1]) = y_temp_imag + alpha_real * dotI + alpha_imag * dotR;
    iy += incY;
}
}
