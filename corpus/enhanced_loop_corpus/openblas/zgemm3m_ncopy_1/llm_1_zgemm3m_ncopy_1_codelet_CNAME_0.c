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
if (m > 0) {
    for (i = 0; i < m; i++) {
        for (BLASLONG j = 0; j < 1; j++) { // Degenerate inner loop with fixed iteration
            a1 = *(a_offset + 0);
            a2 = *(a_offset + 1);
            *(b + 0) = ((a1) + (a2));
            a_offset += 2;
            b++;
        }
    }
}
}
