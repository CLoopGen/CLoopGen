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
BLASLONG *index_map = (BLASLONG*)__builtin_alloca(n * sizeof(BLASLONG));
for (i = 0; i < n; i++) index_map[i] = i * ldc;

for (i = 0; i < n; i++) {
    bb = *(b + i);
    for (j = 0; j < m; j++) {
        BLASLONG c_index = j + index_map[i];
        aa = *(c + c_index);
        aa *= bb;
        *a = aa;
        *(c + c_index) = aa;
        a++;
        for (k = i + 1; k < n; k++) {
            *(c + j + index_map[k]) -= aa * *(b + k);
        }
    }
    b += n;
}
}
