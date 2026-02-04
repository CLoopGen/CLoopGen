#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float beta;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    int idx_diag = 2 * (ldc * i + i);
    float temp_real = (((float *)C)[idx_diag]) * beta;
    float temp_imag = (((float *)C)[idx_diag + 1]);
    (((float *)C)[idx_diag]) = temp_real;
    (((float *)C)[idx_diag + 1]) = 0.;
    for (j = i + 1; j < N; j++) {
        int idx_off = 2 * (ldc * i + j);
        float val_real = (((float *)C)[idx_off]);
        float val_imag = (((float *)C)[idx_off + 1]);
        (((float *)C)[idx_off]) = val_real * beta;
        (((float *)C)[idx_off + 1]) = val_imag * beta;
    }
}
}
