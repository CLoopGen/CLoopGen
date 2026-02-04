#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG i;
extern float *a_offset1;
extern float *b_offset;
extern float a1;
extern float a2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    BLASLONG idx = i * 2;
    a1 = *(a_offset1 + idx);
    a2 = *(a_offset1 + idx + 1);
    *(b_offset + i) = ((a1) + (a2));
}
}
