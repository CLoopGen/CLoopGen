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
// Flattened loop nesting: combine inner loops into one using conditional logic
for (j = n; j > 0; j--) {
    c_offset1 = c_offset;
    c_offset += ldc;
    i = chunk * 8 + remain;  // Total number of elements to zero
    for (BLASLONG idx = 0; idx < i; idx++) {
        if (idx < chunk * 8 && (idx % 8) == 0 && idx + 8 <= chunk * 8) {
            // Unroll every 8 consecutive elements as in original chunk loop
            *(c_offset1 + 0) = 0.F;
            *(c_offset1 + 1) = 0.F;
            *(c_offset1 + 2) = 0.F;
            *(c_offset1 + 3) = 0.F;
            *(c_offset1 + 4) = 0.F;
            *(c_offset1 + 5) = 0.F;
            *(c_offset1 + 6) = 0.F;
            *(c_offset1 + 7) = 0.F;
            c_offset1 += 8;
            idx += 7; // Skip ahead by 7 since we processed 8 elements
        } else if (idx >= chunk * 8) {
            // Handle remaining elements
            *c_offset1 = 0.F;
            c_offset1++;
        }
    }
}
}
