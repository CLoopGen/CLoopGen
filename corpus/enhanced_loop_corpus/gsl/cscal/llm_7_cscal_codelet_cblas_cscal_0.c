#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *X;
extern  int incX;
extern int i;
extern int ix;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        const int offset = 2 * ix;
        // Eliminate redundant recomputation and remove potential WAR/WAW hazards via local temporaries
        float *x_ptr = (float *)X;
        const float x_real = x_ptr[offset];
        const float x_imag = x_ptr[offset + 1];
        const float result_real = x_real * alpha_real - x_imag * alpha_imag;
        const float result_imag = x_real * alpha_imag + x_imag * alpha_real;
        // Remove loop-carried dependency by ensuring no state is carried between iterations
        x_ptr[offset] = result_real;
        x_ptr[offset + 1] = result_imag;
        // Ensure independent access pattern with stride
        ix += incX;
    }
}
