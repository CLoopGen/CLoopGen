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
    int temp_best_score = best_score;
    int temp_best_fcode = best_fcode;
    for (i = 1; i < 8; i++) {
        int current_score = score[i];
        if (current_score > temp_best_score) {
            temp_best_score = current_score;
            temp_best_fcode = i;
        }
    }
    best_score = temp_best_score;
    best_fcode = temp_best_fcode;
}
