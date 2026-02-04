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
float *local_a = a;
for (i = 0; i < m; i++) {
    aa = *(local_a + i);
    float aa_scaled = aa;
    for (j = 0; j < n; j++) {
        BLASLONG index = i + j * ldc;
        bb = *(c + index);
        bb *= aa_scaled;
        *(c + index) = bb;
        *b = bb;
        b++;
        float *c_col = c + j * ldc;
        float *a_ptr = local_a + m;
        for (k = i + 1; k < m; k++) {
            *(c_col + k) -= bb * *(a_ptr + k);
        }
    }
    local_a += m;
}
}
