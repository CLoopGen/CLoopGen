#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG i;
extern float *a_offset1;
extern float *a_offset2;
extern float *a_offset3;
extern float *a_offset4;
extern float *b_offset;
extern float a1;
extern float a2;
extern float a3;
extern float a4;
extern float a5;
extern float a6;
extern float a7;
extern float a8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
long stride = 2;
long offset_a[4] = {0, 0, 0, 0}; // Simulate base offsets for each input array
long offset_b = 0;

for (i = 0; i < m; i++) {
    a1 = *(a_offset1 + offset_a[0]);
    a2 = *(a_offset1 + offset_a[0] + 1);
    a3 = *(a_offset2 + offset_a[1]);
    a4 = *(a_offset2 + offset_a[1] + 1);
    a5 = *(a_offset3 + offset_a[2]);
    a6 = *(a_offset3 + offset_a[2] + 1);
    a7 = *(a_offset4 + offset_a[3]);
    a8 = *(a_offset4 + offset_a[3] + 1);

    *(b_offset + offset_b)     = a1 + a2;
    *(b_offset + offset_b + 1) = a3 + a4;
    *(b_offset + offset_b + 2) = a5 + a6;
    *(b_offset + offset_b + 3) = a7 + a8;

    offset_a[0] += stride;
    offset_a[1] += stride;
    offset_a[2] += stride;
    offset_a[3] += stride;
    offset_b += 4;
}
}
