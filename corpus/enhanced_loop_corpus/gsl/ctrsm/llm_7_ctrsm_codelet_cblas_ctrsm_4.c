#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *B;
extern  int ldb;
extern int i;
extern int j;
extern int n1;
extern int n2;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *B_float = (float *)B;
    float prev_real = 0.0f, prev_imag = 0.0f;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            int idx = 2 * (ldb * i + j);
            float current_real = B_float[idx];
            float current_imag = B_float[idx + 1];

            // Introduce a loop-carried dependency: mix with previous iteration's output
            if (i > 0 || j > 0) {
                B_float[idx]     = alpha_real * current_real - alpha_imag * current_imag + prev_real * 0.1f;
                B_float[idx + 1] = alpha_real * current_imag + alpha_imag * current_real + prev_imag * 0.1f;
            } else {
                B_float[idx]     = alpha_real * current_real - alpha_imag * current_imag;
                B_float[idx + 1] = alpha_real * current_imag + alpha_imag * current_real;
            }

            // Update prev values to create RAW and WAW dependencies across iterations
            prev_real = current_real;
            prev_imag = current_imag;
        }
    }
}
