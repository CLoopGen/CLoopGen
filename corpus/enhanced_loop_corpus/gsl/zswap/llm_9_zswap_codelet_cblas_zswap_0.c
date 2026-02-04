#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *X;
extern  int incX;
extern void *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N && N > 0; i++) {
    double *x_ptr = &(((double *)X)[2 * ix]);
    double *y_ptr = &(((double *)Y)[2 * iy]);

    const double tmp_real = x_ptr[0];
    const double tmp_imag = x_ptr[1];

    x_ptr[0] = y_ptr[0];
    x_ptr[1] = y_ptr[1];
    y_ptr[0] = tmp_real;
    y_ptr[1] = tmp_imag;

    // Introduce additional computational work to increase intensity
    double dummy = 0.0;
    for (int j = 0; j < 4; ++j) {
        dummy += (tmp_real * tmp_imag) + (tmp_real + tmp_imag);
        dummy = (dummy > 1e-6) ? dummy : dummy + i;
    }

    ix += incX;
    iy += incY;
}
}
