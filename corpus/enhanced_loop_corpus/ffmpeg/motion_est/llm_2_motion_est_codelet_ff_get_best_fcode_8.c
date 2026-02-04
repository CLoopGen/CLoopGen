#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int score[8];
extern int i;
extern int best_fcode;
extern int best_score;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2, unrolled to process two elements per iteration
    best_score = score[0];
    best_fcode = 0;
    for (i = 2; i < 8; i += 2) {
        if (score[i] > best_score) {
            best_score = score[i];
            best_fcode = i;
        }
        // Handle odd index within stride
        if (i+1 < 8 && score[i+1] > best_score) {
            best_score = score[i+1];
            best_fcode = i+1;
        }
    }
    // Final check for index 1 if not covered
    if (score[1] > best_score) {
        best_score = score[1];
        best_fcode = 1;
    }
}
