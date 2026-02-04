#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG n;
extern float *a;
extern float *b;
extern float *c;
extern BLASLONG ldc;
extern float aa;
extern float bb;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = n - 1; i >= 0; i--) {
    BLASLONG b_offset = i;
    bb = *(b + b_offset);
    BLASLONG base_idx_c = i * ldc;
    for (j = 0; j < m; j++) {
        BLASLONG c_idx = base_idx_c + j;
        aa = *(c + c_idx);
        aa *= bb;
        *(a + j) = aa;
        *(c + c_idx) = aa;
        float temp = aa;
        for (k = 0; k < i; k++) {
            BLASLONG update_idx = j + k * ldc;
            BLASLONG b_idx = k;
            *(c + update_idx) -= temp * *(b + b_idx);
        }
    }
    a += m;
}
}
