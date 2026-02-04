#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *Y;
extern  int incY;
extern int i;
extern  double beta_real;
extern  double beta_imag;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_real[32] = {0}, temp_imag[32] = {0};
    int local_iy = iy;
    for (i = 0; i < N; i++) {
        const int offset = 2 * (local_iy);
        const double y_real = (((double *)Y)[offset]);
        const double y_imag = (((double *)Y)[offset + 1]);
        const double tmpR = y_real * beta_real - y_imag * beta_imag;
        const double tmpI = y_real * beta_imag + y_imag * beta_real;
        temp_real[i % 32] = tmpR;
        temp_imag[i % 32] = tmpI;
        local_iy += incY;
    }
    for (i = 0; i < N; i++) {
        const int idx = (i / 32) * 32 + (i % 32);
        if (i < N) {
            const int offset = 2 * (iy + i * incY);
            (((double *)Y)[offset]) = temp_real[i % 32];
            (((double *)Y)[offset + 1]) = temp_imag[i % 32];
        }
    }
    iy = local_iy;
}
