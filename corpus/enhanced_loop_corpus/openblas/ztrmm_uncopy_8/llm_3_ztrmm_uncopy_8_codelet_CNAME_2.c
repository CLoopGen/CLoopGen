#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing via offset array
    // Use a fixed offset table to simulate indirect access pattern and increase stride predictability
    static const int offsets[8] = {0, 1, 0, 1, 0, 1, 0, 1}; // Repeats local offsets
    float *base_ptrs[4] = {ao1, ao2, ao3, ao4};

    for (ii = 0; ii < 4; ii++) {
        for (BLASLONG j = 0; j < 8; j++) {
            BLASLONG ptr_idx = j / 2;  // Two elements per pointer
            b[j] = *(base_ptrs[ptr_idx] + offsets[j]);
        }
        // Update base pointers
        ao1 += 2;
        ao2 += 2;
        ao3 += 2;
        ao4 += 2;
        base_ptrs[0] = ao1;
        base_ptrs[1] = ao2;
        base_ptrs[2] = ao3;
        base_ptrs[3] = ao4;
        b += 8;
    }
}
