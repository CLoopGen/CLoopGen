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
    float *y_ptr = (float *)Y;
    int local_iy = iy;
    for (i = 0; i < N; i++) {
        int offset = 2 * local_iy;
        float y_real = y_ptr[offset];
        float y_imag = y_ptr[offset + 1];
        float tmpR = y_real * beta_real;
        float tmpI = y_real * beta_imag;
        tmpR -= y_imag * beta_imag;
        tmpI += y_imag * beta_real;
        y_ptr[offset] = tmpR;
        y_ptr[offset + 1] = tmpI;
        local_iy += incY;
    }
    iy = local_iy; // Introduce WAW dependency resolution: update shared iy only once after loop
}
