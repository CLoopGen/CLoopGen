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
for (i = 0; i < n; i += 2) {
    if (i + 1 < n) {
        for (j = 0; j < m; j++) {
            float bb1 = *(b + i);
            float bb2 = *(b + i + 1);
            float aa1 = *(c + j + i * ldc);
            float aa2 = *(c + j + (i + 1) * ldc);
            aa1 *= bb1;
            aa2 *= bb2;
            *a = aa1;
            *(a + 1) = aa2;
            a += 2;
            for (k = i + 1; k < n; k++) {
                *(c + j + k * ldc) -= aa1 * *(b + k);
                *(c + j + k * ldc) -= aa2 * *(b + k);
            }
        }
        b += 2 * n;
    } else {
        bb = *(b + i);
        for (j = 0; j < m; j++) {
            aa = *(c + j + i * ldc);
            aa *= bb;
            *a = aa;
            a++;
            for (k = i + 1; k < n; k++) {
                *(c + j + k * ldc) -= aa * *(b + k);
            }
        }
        b += n;
    }
}
}
