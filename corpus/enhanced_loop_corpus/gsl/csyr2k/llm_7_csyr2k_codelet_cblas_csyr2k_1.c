#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        int base_idx_i = ldc * i;
        for (j = 0; j <= i; j++) {
            int idx = 2 * (base_idx_i + j);
            // Eliminate WAW and WAR hazards by writing only once with combined data
            ((float *)C)[idx] = 0.;
        }
        // Add loop-carried dependency: each iteration depends on completion of inner loop
        if (i > 0) {
            ((float *)C)[2 * (ldc * i)] += ((float *)C)[2 * (ldc * (i-1))]; // WAW turned into RAW across iterations
        }
    }
}
