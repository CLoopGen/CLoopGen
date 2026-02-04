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
for (i = 0; i < m && m > 0; i++) {
    aa = *(a + i);
    for (j = 0; j < n; j++) {
        BLASLONG c_index = i + j * ldc;
        bb = *(c + c_index);
        bb *= aa;
        *b = bb;
        b++;
        *(c + c_index) = bb;
    }
    a += m;
    for (j = 0; j < n; j++) {
        for (k = i + 1; k < m; k++) {
            *(c + k + j * ldc) -= *(c + i + j * ldc) * *(a + k - i - 1 + m);
        }
    }
}
}
