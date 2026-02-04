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
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_accum_real[1024] = {0}; // Assume lenY <= 1024 for stack allocation
    double temp_accum_imag[1024] = {0};
    int iy_base = (incY > 0 ? 0 : (lenY - 1) * (-incY));
    for (j = 0; j < lenX; j++) {
        double x_real = (((const double *)X)[2 * ix]);
        double x_imag = (((const double *)X)[2 * ix + 1]);
        double tmpR = alpha_real * x_real - alpha_imag * x_imag;
        double tmpI = alpha_real * x_imag + alpha_imag * x_real;
        int iy = iy_base;
        for (i = 0; i < lenY; i++) {
            const double A_real = (((const double *)A)[2 * (lda * j + i)]);
            const double A_imag = (((const double *)A)[2 * (lda * j + i) + 1]);
            temp_accum_real[i] += A_real * tmpR - A_imag * tmpI;
            temp_accum_imag[i] += A_real * tmpI + A_imag * tmpR;
            iy += incY;
        }
        ix += incX;
    }
    // Final write-back to Y with incY stride
    int iy_final = (incY > 0 ? 0 : (lenY - 1) * (-incY));
    for (i = 0; i < lenY; i++) {
        (((double *)Y)[2 * iy_final]) += temp_accum_real[i];
        (((double *)Y)[2 * iy_final + 1]) += temp_accum_imag[i];
        iy_final += incY;
    }
}
