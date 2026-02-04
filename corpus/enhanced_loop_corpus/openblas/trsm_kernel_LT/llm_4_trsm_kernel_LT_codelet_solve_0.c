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
for (i = 0; i < m; i++) {
    aa = *(a + i);
    if (aa != 0.0f) {
        for (j = 0; j < n; j++) {
            bb = *(c + i + j * ldc);
            bb *= aa;
            *b = bb;
            *(c + i + j * ldc) = bb;
            b++;
            for (k = i + 1; k < m; k++) {
                *(c + k + j * ldc) -= bb * *(a + k);
            }
        }
    } else {
        for (j = 0; j < n; j++) {
            *b = 0.0f;
            b++;
        }
    }
    a += m;
}
}
