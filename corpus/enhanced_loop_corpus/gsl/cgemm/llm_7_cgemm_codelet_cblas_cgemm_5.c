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
// Reorder loops to change data access pattern and introduce WAR/WAW dependencies differently
// Now: j-k-i ordering, accumulating into C[i][j] indirectly through temporary array per i
float **temp_real = (float**)malloc(n1 * sizeof(float*));
float **temp_imag = (float**)malloc(n1 * sizeof(float*));
for (int ii = 0; ii < n1; ii++) {
    temp_real[ii] = (float*)calloc(n2, sizeof(float));
    temp_imag[ii] = (float*)calloc(n2, sizeof(float));
}

for (j = 0; j < n2; j++) {
    for (k = 0; k < K; k++) {
        for (i = 0; i < n1; i++) {
            const float Fki_real = (((const float *)F)[2 * (ldf * k + i)]);
            const float Fki_imag = conjF * (((const float *)F)[2 * (ldf * k + i) + 1]);
            const float Gjk_real = (((const float *)G)[2 * (ldg * j + k)]);
            const float Gjk_imag = conjG * (((const float *)G)[2 * (ldg * j + k) + 1]);

            // Accumulate into local temp arrays to create new RAW/WAR patterns across k
            temp_real[i][j] += Fki_real * Gjk_real - Fki_imag * Gjk_imag;
            temp_imag[i][j] += Fki_real * Gjk_imag + Fki_imag * Gjk_real;
        }
    }
}

// Final update of C outside inner loops, eliminating repeated memory writes
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        ((float*)C)[2 * (ldc * i + j)]     += alpha_real * temp_real[i][j] - alpha_imag * temp_imag[i][j];
        ((float*)C)[2 * (ldc * i + j) + 1] += alpha_real * temp_imag[i][j] + alpha_imag * temp_real[i][j];
    }
    free(temp_real[i]);
    free(temp_imag[i]);
}
free(temp_real);
free(temp_imag);
}
