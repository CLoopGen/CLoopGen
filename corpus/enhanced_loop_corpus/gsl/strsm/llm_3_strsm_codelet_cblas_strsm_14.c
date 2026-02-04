#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *A;
extern  int lda;
extern float *B;
extern  int ldb;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern  int nonunit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *base_Bi;
for (i = 0; i < n1; i++) {
    base_Bi = &B[i * ldb];
    for (j = 0; j < n2; j++) {
        ptrdiff_t Aj_off = j * (lda + 1);
        ptrdiff_t Bik_off = j;
        if (nonunit) {
            float Ajj = A[Aj_off];
            base_Bi[Bik_off] /= Ajj;
        }
        {
            float Bij = base_Bi[Bik_off];
            for (k = j + 1; k < n2; k++) {
                ptrdiff_t Akj_off = k * lda + j;
                ptrdiff_t Bik_idx = k;
                base_Bi[Bik_idx] -= A[Akj_off] * Bij;
            }
        }
    }
}
}
