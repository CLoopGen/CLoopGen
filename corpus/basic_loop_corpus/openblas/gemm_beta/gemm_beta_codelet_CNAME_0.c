#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG n;
extern BLASLONG ldc;
extern BLASLONG i;
extern BLASLONG j;
extern BLASLONG chunk;
extern BLASLONG remain;
extern float *c_offset1;
extern float *c_offset;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = n; j > 0; j--) {
    c_offset1 = c_offset;
    c_offset += ldc;
    for (i = chunk; i > 0; i--) {
        *(c_offset1 + 0) = 0.F;
        *(c_offset1 + 1) = 0.F;
        *(c_offset1 + 2) = 0.F;
        *(c_offset1 + 3) = 0.F;
        *(c_offset1 + 4) = 0.F;
        *(c_offset1 + 5) = 0.F;
        *(c_offset1 + 6) = 0.F;
        *(c_offset1 + 7) = 0.F;
        c_offset1 += 8;
    }
    for (i = remain; i > 0; i--) {
        *c_offset1 = 0.F;
        c_offset1++;
    }
}

}
