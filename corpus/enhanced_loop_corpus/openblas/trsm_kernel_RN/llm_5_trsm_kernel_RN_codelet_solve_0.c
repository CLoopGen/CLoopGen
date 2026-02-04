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
for (i = 0; i < n; i++) {
    bb = *(b + i);
    for (j = 0; j < m; j++) {
        aa = *(c + j + i * ldc);
        aa *= bb;
        *a = aa;
        *(c + j + i * ldc) = aa;
        a++;
        if (aa != 0.0f) {
            for (k = i + 1; k < n; k++) {
                *(c + j + k * ldc) -= aa * *(b + k);
            }
        }
    }
    b += n;
}
}
