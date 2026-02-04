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
    bb = b[i];
    float *c_row = c + i * ldc;
    float *b_ptr = b;
    for (j = 0; j < m; j++) {
        aa = c_row[j];
        aa *= bb;
        a[j] = aa;
        c_row[j] = aa;
        for (k = 0; k < i; k++) {
            c[j + k * ldc] -= aa * b_ptr[k];
        }
    }
    b -= n;
    a += m;
}
}
