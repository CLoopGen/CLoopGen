#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern float *a_offset;
extern float a1;
extern float a2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    if (i % 2 == 0) {
        a1 = *(a_offset + 0);
        a2 = *(a_offset + 1);
        *(b + 0) = ((a1) + (a2));
    } else {
        *(b + 0) = 0.0f;
    }
    a_offset += lda;
    b++;
}
}
