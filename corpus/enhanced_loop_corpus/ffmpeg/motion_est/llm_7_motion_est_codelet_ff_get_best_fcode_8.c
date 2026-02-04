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
    int candidate_score = best_score;
    int candidate_fcode = best_fcode;
    for (i = 1; i < 8; i++) {
        int s = score[i];
        int greater = (s > candidate_score);
        candidate_score = greater ? s : candidate_score;
        candidate_fcode = greater ? i : candidate_fcode;
    }
    best_score = candidate_score;
    best_fcode = candidate_fcode;
}
