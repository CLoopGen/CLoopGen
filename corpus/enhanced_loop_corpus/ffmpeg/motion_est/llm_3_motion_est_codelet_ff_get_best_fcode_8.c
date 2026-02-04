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
    // Variant 2: Indirect array access using an index mapping array (simulating indirect or gather-style access)
    int indices[7];
    for (int temp_i = 0; temp_i < 7; temp_i++) {
        indices[temp_i] = temp_i + 1; // indices = {1,2,3,4,5,6,7}
    }
    best_score = score[indices[0]];
    best_fcode = indices[0];
    for (i = 1; i < 7; i++) {
        int idx = indices[i]; // Indirect access via index array
        if (score[idx] > best_score) {
            best_score = score[idx];
            best_fcode = idx;
        }
    }
}
