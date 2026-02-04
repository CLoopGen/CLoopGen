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
        BLASLONG index = j + i * ldc;
        aa = *(c + index);
        aa *= bb;
        *(c + index) = aa;
        *a = aa;
        a++;
        for (k = i + 1; k < n; k++) {
            BLASLONG update_index = j + k * ldc;
            *(c + update_index) = *(c + update_index) - aa * *(b + k);
        }
    }
    b += n;
}
}
