#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  void *A;
extern  int lda;
extern  void *B;
extern  int ldb;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n1; i++) {
    float local_C_buffer[2 * 1024]; // Local accumulation buffer to remove WAW and RAW hazards
    // Initialize local buffer to zero for j-th row of C[i][*]
    for (int jj = 0; jj < n2 && jj < 1024; jj++) {
        local_C_buffer[2 * jj] = 0.0f;
        local_C_buffer[2 * jj + 1] = 0.0f;
    }
    for (j = 0; j < n2; j++) {
        const float Bij_real = (((const float *)B)[2 * (ldb * i + j)]);
        const float Bij_imag = (((const float *)B)[2 * (ldb * i + j) + 1]);
        const float temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const float temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        float temp2_real = 0.;
        float temp2_imag = 0.;
        // Reverse loop order to create different loop-carried dependency direction
        for (k = j - 1; k >= 0; k--) { // Backward loop: introduces anti-dependence (WAR) if transformed
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = (((const float *)A)[2 * (j * lda + k) + 1]);
            const float Bik_real = (((const float *)B)[2 * (ldb * i + k)]);
            const float Bik_imag = (((const float *)B)[2 * (ldb * i + k) + 1]);
            // Accumulate into local buffer instead of directly to global C — removes RAW/WAW across iterations
            local_C_buffer[2 * k] += temp1_real * Ajk_real - temp1_imag * Ajk_imag;
            local_C_buffer[2 * k + 1] += temp1_real * Ajk_imag + temp1_imag * Ajk_real;
            temp2_real += Bik_real * Ajk_real + Bik_imag * Ajk_imag; // Eliminate negation: change algebraic expression slightly but valid
            temp2_imag += -Bik_real * Ajk_imag + Bik_imag * Ajk_real;
        }
        {
            const float Ajj_real = (((const float *)A)[2 * (j * lda + j)]);
            local_C_buffer[2 * j] += temp1_real * Ajj_real;
            local_C_buffer[2 * j + 1] += temp1_imag * Ajj_real;
        }
        local_C_buffer[2 * j] += alpha_real * temp2_real - alpha_imag * temp2_imag;
        local_C_buffer[2 * j + 1] += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
    // Flush local buffer to global memory after processing row i — eliminates intra-row race conditions
    for (int jj = 0; jj < n2 && jj < 1024; jj++) {
        (((float *)C)[2 * (i * ldc + jj)]) += local_C_buffer[2 * jj];
        (((float *)C)[2 * (i * ldc + jj) + 1]) += local_C_buffer[2 * jj + 1];
    }
}
}
