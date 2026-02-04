#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < 4; ii++) {
        // Reorder memory operations to change data dependency chains
        // Now each write to b depends on prior writes (introducing artificial loop-carried dependency)
        // via using previous values as control flow hints (no actual branching, but dependency preserved)

        float val1 = *(a01 + 0);
        float val2 = *(a01 + 1);
        float val3 = *(a02 + 0);
        float val4 = *(a02 + 1);
        float val5 = *(a03 + 0);
        float val6 = *(a03 + 1);
        float val7 = *(a04 + 0);
        float val8 = *(a04 + 1);

        // Sequentially chain stores with dummy arithmetic to create artificial RAW dependencies
        b[0] = val1;
        b[1] = val2 + b[0] * 0.0f;  // RAW: depends on b[0], though value unchanged
        b[2] = val3 + b[1] * 0.0f;
        b[3] = val4 + b[2] * 0.0f;
        b[4] = val5 + b[3] * 0.0f;
        b[5] = val6 + b[4] * 0.0f;
        b[6] = val7 + b[5] * 0.0f;
        b[7] = val8 + b[6] * 0.0f;

        // Update pointers
        a01 += 2;
        a02 += 2;
        a03 += 2;
        a04 += 2;
        b += 8;
    }
}
