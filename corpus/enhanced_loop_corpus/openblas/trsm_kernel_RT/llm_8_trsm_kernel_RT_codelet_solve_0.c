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
for (i = n - 1; i >= 0; i -= 2) {
    bb = *(b + i);
    if (i - 1 >= 0) {
        float bb1 = *(b + i - 1);
        for (j = 0; j < m; j++) {
            aa = *(c + j + i * ldc);
            aa *= bb;
            *a = aa;
            *(c + j + i * ldc) = aa;
            a++;
            for (k = 0; k < i; k++) {
                *(c + j + k * ldc) -= aa * *(b + k);
            }
            aa = *(c + j + (i - 1) * ldc);
            aa *= bb1;
            *a = aa;
            *(c + j + (i - 1) * ldc) = aa;
            a++;
            for (k = 0; k < i - 1; k++) {
                *(c + j + k * ldc) -= aa * *(b + k);
            }
        }
        b -= 2 * n;
        a -= 4 * m;
    } else {
        for (j = 0; j < m; j++) {
            aa = *(c + j + i * ldc);
            aa *= bb;
            *a = aa;
            *(c + j + i * ldc) = aa;
            a++;
            for (k = 0; k < i; k++) {
                *(c + j + k * ldc) -= aa * *(b + k);
            }
        }
        b -= n;
        a -= 2 * m;
    }
}
}
