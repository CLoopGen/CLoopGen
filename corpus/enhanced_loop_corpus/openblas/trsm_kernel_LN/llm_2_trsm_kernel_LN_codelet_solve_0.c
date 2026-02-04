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
for (i = m - 1; i >= 0; i--) {
    aa = a[i];
    for (j = 0; j < n; j++) {
        BLASLONG index_c = i + j * ldc;
        bb = c[index_c];
        bb *= aa;
        b[j] = bb;
        c[index_c] = bb;
        for (k = 0; k < i; k++) {
            c[k + j * ldc] -= bb * a[k];
        }
    }
    a -= m;
    b += n;
}
}
