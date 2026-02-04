#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern float *b;
extern BLASLONG i;
extern float *a_offset;
extern float a1;
extern float a2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i += 2) {
    a1 = *(a_offset + 0);
    a2 = *(a_offset + 1);
    *(b + 0) = ((a1) + (a2));
    a1 = *(a_offset + 2);
    a2 = *(a_offset + 3);
    *(b + 1) = ((a1) + (a2));
    a_offset += 4;
    b += 2;
}
}
