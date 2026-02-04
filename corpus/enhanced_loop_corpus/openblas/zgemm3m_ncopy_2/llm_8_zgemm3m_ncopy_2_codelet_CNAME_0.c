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
for (i = 0; i < m; i += 2) {
    if (i + 1 < m) {
        a1 = *(a_offset1 + 0);
        a2 = *(a_offset1 + 1);
        a3 = *(a_offset2 + 0);
        a4 = *(a_offset2 + 1);
        *(b_offset + 0) = ((a1) + (a2));
        *(b_offset + 1) = ((a3) + (a4));

        float b1 = *(a_offset1 + 2);
        float b2 = *(a_offset1 + 3);
        float b3 = *(a_offset2 + 2);
        float b4 = *(a_offset2 + 3);
        *(b_offset + 2) = ((b1) + (b2));
        *(b_offset + 3) = ((b3) + (b4));

        a_offset1 += 4;
        a_offset2 += 4;
        b_offset += 4;
    } else {
        a1 = *(a_offset1 + 0);
        a2 = *(a_offset1 + 1);
        a3 = *(a_offset2 + 0);
        a4 = *(a_offset2 + 1);
        *(b_offset + 0) = ((a1) + (a2));
        *(b_offset + 1) = ((a3) + (a4));
        break;
    }
}
}
