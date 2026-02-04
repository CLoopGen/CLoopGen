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
for (BLASLONG outer = 0; outer < m; outer += 2) {
    for (BLASLONG inner = 0; inner < 2 && (outer + inner) < m; inner++) {
        a1 = *(a_offset + 0);
        a2 = *(a_offset + 1);
        *(b + 0) = ((a1) + (a2));
        a_offset += 2;
        b++;
    }
}
}
