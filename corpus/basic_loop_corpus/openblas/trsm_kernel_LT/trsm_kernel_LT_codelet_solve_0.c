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
    a += m;
}

}
