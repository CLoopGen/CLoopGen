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
    int temp_score = last_score;
    int temp_i = last_i;
    int temp_level = last_level;
    int temp_run = last_run;

    for (i = survivor[0]; i <= last_non_zero + 1; i++) {
        int score = score_tab[i];
        if (i)
            score += lambda * 2;
        if (score < temp_score) {
            temp_score = score;
            temp_i = i;
            temp_level = level_tab[i];
            temp_run = run_tab[i];
        }
    }

    last_score = temp_score;
    last_i = temp_i;
    last_level = temp_level;
    last_run = temp_run;
}
