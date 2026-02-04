#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *Y;
extern  int incY;
extern int i;
extern  float beta_real;
extern  float beta_imag;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i += 2) {
        if (i + 1 < N) {
            const float y_real1 = (((float *)Y)[2 * (iy)]);
            const float y_imag1 = (((float *)Y)[2 * (iy) + 1]);
            const float tmpR1 = y_real1 * beta_real - y_imag1 * beta_imag;
            const float tmpI1 = y_real1 * beta_imag + y_imag1 * beta_real;

            iy += incY;

            const float y_real2 = (((float *)Y)[2 * (iy)]);
            const float y_imag2 = (((float *)Y)[2 * (iy) + 1]);
            const float tmpR2 = y_real2 * beta_real - y_imag2 * beta_imag;
            const float tmpI2 = y_real2 * beta_imag + y_imag2 * beta_real;

            (((float *)Y)[2 * (iy) - 2 * incY]) = tmpR1;
            (((float *)Y)[2 * (iy) - 2 * incY + 1]) = tmpI1;
            (((float *)Y)[2 * (iy)]) = tmpR2;
            (((float *)Y)[2 * (iy) + 1]) = tmpI2;

            iy += incY;
        } else {
            const float y_real = (((float *)Y)[2 * (iy)]);
            const float y_imag = (((float *)Y)[2 * (iy) + 1]);
            const float tmpR = y_real * beta_real - y_imag * beta_imag;
            const float tmpI = y_real * beta_imag + y_imag * beta_real;
            (((float *)Y)[2 * (iy)]) = tmpR;
            (((float *)Y)[2 * (iy) + 1]) = tmpI;
            iy += incY;
        }
    }
}
