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
float *c_base = c;
for (i = 0; i < m; i++) {
    aa = a[i]; // Consecutive base access via array notation
    for (j = 0; j < n; j++) {
        int c_index = i + j * ldc;
        bb = c_base[c_index];
        bb *= aa;
        b[j] = bb; // Store output consecutively in b
        c_base[c_index] = bb;
        for (k = i + 1; k < m; k++) {
            c_base[k + j * ldc] -= bb * a[k]; // Uniform direct indexing with base pointer
        }
    }
    b += n; // Advance b by full row length for next iteration
    a += m; // Maintain original advancement of a
}
}
