#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG k;
extern float *ptrba;
extern float *ptrbb;
extern float res0_0;
extern float res0_1;
extern float res1_0;
extern float res1_1;
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG *index_array_a = (BLASLONG*)ptrba; // Reinterpret for indirect indexing (simulated)
BLASLONG *index_array_b = (BLASLONG*)ptrbb;
float *data_ptr_a = (float*)(&index_array_a[temp]);
float *data_ptr_b = (float*)(&index_array_b[temp]);

for (k = 0; k < temp; k++) {
    BLASLONG offset_a = index_array_a[k] % 2; // Simulate irregular access pattern
    BLASLONG offset_b = index_array_b[k] % 2;
    b0 = data_ptr_b[offset_b * 2];
    b1 = data_ptr_b[offset_b * 2 + 1];
    a0 = data_ptr_a[offset_a * 2];
    res0_0 += a0 * b0;
    res1_0 += a0 * b1;
    a1 = data_ptr_a[offset_a * 2 + 1];
    res0_1 += a1 * b0;
    res1_1 += a1 * b1;
}
}
