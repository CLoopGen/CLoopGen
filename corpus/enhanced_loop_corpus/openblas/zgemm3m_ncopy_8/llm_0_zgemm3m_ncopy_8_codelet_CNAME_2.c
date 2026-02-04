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
        // Process two iterations at once
        float a1_0 = *(a_offset1 + 0);
        float a2_0 = *(a_offset1 + 1);
        float a3_0 = *(a_offset2 + 0);
        float a4_0 = *(a_offset2 + 1);
        *(b_offset + 0) = a1_0 + a2_0;
        *(b_offset + 1) = a3_0 + a4_0;

        float a1_1 = *(a_offset1 + 2);
        float a2_1 = *(a_offset1 + 3);
        float a3_1 = *(a_offset2 + 2);
        float a4_1 = *(a_offset2 + 3);
        *(b_offset + 2) = a1_1 + a2_1;
        *(b_offset + 3) = a3_1 + a4_1;

        a_offset1 += 4;
        a_offset2 += 4;
        b_offset += 4;
    } else {
        // Handle leftover iteration
        float a1 = *(a_offset1 + 0);
        float a2 = *(a_offset1 + 1);
        float a3 = *(a_offset2 + 0);
        float a4 = *(a_offset2 + 1);
        *(b_offset + 0) = a1 + a2;
        *(b_offset + 1) = a3 + a4;
        break;
    }
}
}
