#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *Y;
extern  int incY;
extern int i;
extern int lenY;
extern  float beta_real;
extern  float beta_imag;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < lenY; i++) {
    float *y_ptr = &(((float *)Y)[2 * iy]);
    const float y_real = y_ptr[0];
    const float y_imag = y_ptr[1];

    float tmpR = y_real;
    float tmpI = y_imag;

    for (int j = 0; j < 3; j++) {
        tmpR = tmpR * beta_real - tmpI * beta_imag;
        tmpI = y_real * beta_imag + y_imag * beta_real;
    }

    y_ptr[0] = tmpR;
    y_ptr[1] = tmpI;

    iy += incY;
}
}
