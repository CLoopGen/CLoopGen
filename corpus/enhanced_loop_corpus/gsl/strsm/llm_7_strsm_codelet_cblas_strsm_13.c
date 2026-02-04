#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float alpha;
extern float *B;
extern  int ldb;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_accum = 1.0f;
    for (i = 0; i < n1; i++) {
        local_accum = alpha; // Reinitialize per i (introduces loop-carried anti-dependence if reused, but not here)
        for (j = 0; j < n2; j += 2) { // Modify stride to change access pattern and dependencies
            if (j + 1 < n2) {
                // Introduce artificial dependence: result at j depends on j+1
                float t1 = B[ldb * i + j] * alpha;
                float t2 = B[ldb * i + j + 1] * alpha;
                B[ldb * i + j] = t2;     // WAR hazard introduced: write j after using j+1
                B[ldb * i + j + 1] = t1; // Swap values — creates intra-iteration dependence
            } else {
                B[ldb * i + j] *= alpha;
            }
        }
    }
}
