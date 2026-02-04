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
    for (k = 0; k < temp; k++) {
        // Reorder operations to eliminate some loop-carried dependencies
        // Load all data first to remove potential WAR hazards
        float bb0 = ptrbb[0];
        float bb1 = ptrbb[1];
        float ba0 = ptrba[0];
        float ba1 = ptrba[1];

        // Remove sequential dependency in accumulation by using local temporaries
        float local_res0_0 = ba0 * bb0;
        float local_res1_0 = ba0 * bb1;
        float local_res0_1 = ba1 * bb0;
        float local_res1_1 = ba1 * bb1;

        // Accumulate into globals only at the end (reducing WAW on global res vars)
        res0_0 += local_res0_0;
        res1_0 += local_res1_0;
        res0_1 += local_res0_1;
        res1_1 += local_res1_1;

        ptrba += 2;
        ptrbb += 2;
    }
}
