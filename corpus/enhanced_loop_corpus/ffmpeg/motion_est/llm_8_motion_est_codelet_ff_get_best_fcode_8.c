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
int temp_score = best_score;
for (i = 1; i < 8; i += 2) {
    if (i + 1 < 8) {
        if (score[i] > temp_score) {
            temp_score = score[i];
            best_fcode = i;
        }
        if (score[i+1] > temp_score) {
            temp_score = score[i+1];
            best_fcode = i+1;
        }
    } else {
        if (score[i] > temp_score) {
            temp_score = score[i];
            best_fcode = i;
        }
    }
}
best_score = temp_score;
}
