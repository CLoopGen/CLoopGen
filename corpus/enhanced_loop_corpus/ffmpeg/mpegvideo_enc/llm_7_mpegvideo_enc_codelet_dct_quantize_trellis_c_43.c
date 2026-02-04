#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int run_tab[65];
extern int level_tab[65];
extern int score_tab[65];
extern int survivor[65];
extern int last_run;
extern int last_level;
extern int last_score;
extern int last_i;
extern int last_non_zero;
extern int i;
extern  int lambda;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_score = last_score;
    int candidate_i = last_i;
    int candidate_level = last_level;
    int candidate_run = last_run;

    for (i = survivor[0]; i <= last_non_zero + 1; i++) {
        int current_score = score_tab[i];
        if (i) {
            current_score += lambda * 2;
        }

        int update_condition = (current_score < prev_score);

        candidate_i = update_condition ? i : candidate_i;
        candidate_level = update_condition ? level_tab[i] : candidate_level;
        candidate_run = update_condition ? run_tab[i] : candidate_run;
        prev_score = update_condition ? current_score : prev_score;
    }

    last_score = prev_score;
    last_i = candidate_i;
    last_level = candidate_level;
    last_run = candidate_run;
}
