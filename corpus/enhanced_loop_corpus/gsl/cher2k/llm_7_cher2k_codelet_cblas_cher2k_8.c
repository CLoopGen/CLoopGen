#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  void *A;
extern  int lda;
extern  void *B;
extern  int ldb;
extern void *C;
extern int i;
extern int j;
extern int k;
extern  float alpha_real;
extern float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reverse loop order to introduce different loop-carried dependency patterns
// and modify data access pattern to create read-after-write opportunities
for (i = N - 1; i >= 0; i--) {
    for (k = K - 1; k >= 0; k--) {
        float Aki_real = (((const float *)A)[2 * (k * lda + i)]);
        float Aki_imag = (((const float *)A)[2 * (k * lda + i) + 1]);
        float Bki_real = (((const float *)B)[2 * (k * ldb + i)]);
        float Bki_imag = (((const float *)B)[2 * (k * ldb + i) + 1]);
        float temp1_real = alpha_real * Aki_real - alpha_imag * (-Aki_imag);
        float temp1_imag = alpha_real * (-Aki_imag) + alpha_imag * Aki_real;
        float temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
        float temp2_imag = -(alpha_real * Bki_imag + alpha_imag * Bki_real);

        // Introduce artificial dependency: use previous result in current computation
        float prev_update = (i == N - 1 || k == K - 1) ? 0.0f : 
                            (((float *)C)[2 * (i * lda + i)]);

        // Modify diagonal contribution using prior state — creates loop-carried WAW dependency
        (((float *)C)[2 * (i * lda + i)]) += 2 * (temp1_real * Bki_real - temp1_imag * Bki_imag) + prev_update;
        (((float *)C)[2 * (i * lda + i) + 1]) = 0.f;

        // Update lower triangular part with reversed index order
        for (j = i - 1; j >= 0; j--) {
            float Akj_real = (((const float *)A)[2 * (k * lda + j)]);
            float Akj_imag = (((const float *)A)[2 * (k * lda + j) + 1]);
            float Bkj_real = (((const float *)B)[2 * (k * ldb + j)]);
            float Bkj_imag = (((const float *)B)[2 * (k * ldb + j) + 1]);

            float update_real = (temp1_real * Bkj_real - temp1_imag * Bkj_imag) +
                                (temp2_real * Akj_real - temp2_imag * Akj_imag);
            float update_imag = (temp1_real * Bkj_imag + temp1_imag * Bkj_real) +
                                (temp2_real * Akj_imag + temp2_imag * Akj_real);

            // Create WAR dependency by reading before write in original order
            // Now we write earlier elements later — changes memory dependency chain
            (((float *)C)[2 * (i * lda + j)]) += update_real;
            (((float *)C)[2 * (i * lda + j) + 1]) += update_imag;
        }
    }
}
}
