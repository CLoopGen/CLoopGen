#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int K;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern int ldf;
extern int ldg;
extern int conjF;
extern int conjG;
extern  float *F;
extern  float *G;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        // Introduce local accumulation arrays to break false dependencies and enable reordering
        float accum_real[2] = {0.0f, 0.0f};
        float accum_imag[2] = {0.0f, 0.0f};
        int k;
        // Split the loop into two parts: even and odd indices to modify data dependency pattern
        for (k = 0; k < K; k += 2) {
            if (k + 1 < K) {
                // Process two iterations at once to create intra-loop dependency changes
                const float Fik0_real = (((const float *)F)[2 * (ldf * i + k)]);
                const float Fik0_imag = conjF * (((const float *)F)[2 * (ldf * i + k) + 1]);
                const float Gjk0_real = (((const float *)G)[2 * (ldg * j + k)]);
                const float Gjk0_imag = conjG * (((const float *)G)[2 * (ldg * j + k) + 1]);

                const float Fik1_real = (((const float *)F)[2 * (ldf * i + k + 1)]);
                const float Fik1_imag = conjF * (((const float *)F)[2 * (ldf * i + k + 1) + 1]);
                const float Gjk1_real = (((const float *)G)[2 * (ldg * j + k + 1)]);
                const float Gjk1_imag = conjG * (((const float *)G)[2 * (ldg * j + k + 1) + 1]);

                // Update both accumulators independently to remove sequential dependency on temp
                accum_real[0] += Fik0_real * Gjk0_real - Fik0_imag * Gjk0_imag;
                accum_imag[0] += Fik0_real * Gjk0_imag + Fik0_imag * Gjk0_real;

                accum_real[1] += Fik1_real * Gjk1_real - Fik1_imag * Gjk1_imag;
                accum_imag[1] += Fik1_real * Gjk1_imag + Fik1_imag * Gjk1_real;
            } else {
                // Handle leftover iteration
                const float Fik_real = (((const float *)F)[2 * (ldf * i + k)]);
                const float Fik_imag = conjF * (((const float *)F)[2 * (ldf * i + k) + 1]);
                const float Gjk_real = (((const float *)G)[2 * (ldg * j + k)]);
                const float Gjk_imag = conjG * (((const float *)G)[2 * (ldg * j + k) + 1]);
                temp_real += Fik_real * Gjk_real - Fik_imag * Gjk_imag;
                temp_imag += Fik_real * Gjk_imag + Fik_imag * Gjk_real;
            }
        }
        // Combine split accumulations
        temp_real += accum_real[0] + accum_real[1];
        temp_imag += accum_imag[0] + accum_imag[1];
        (((float *)C)[2 * (ldc * i + j)]) += alpha_real * temp_real - alpha_imag * temp_imag;
        (((float *)C)[2 * (ldc * i + j) + 1]) += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
