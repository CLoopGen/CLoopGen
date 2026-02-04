#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG i;
extern float *a_offset1;
extern float *a_offset2;
extern float *b_offset;
extern float a1;
extern float a2;
extern float a3;
extern float a4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    a1 = *(a_offset1 + 0);
    a2 = *(a_offset1 + 1);
    *(b_offset + 0) = a1 + a2;

    if (i >= m / 2) {
        a3 = *(a_offset2 + 0);
        a4 = *(a_offset2 + 1);
        *(b_offset + 1) = a3 + a4;
    }

    a_offset1 += 2;
    a_offset2 += 2;
    b_offset += 2;
}
}
