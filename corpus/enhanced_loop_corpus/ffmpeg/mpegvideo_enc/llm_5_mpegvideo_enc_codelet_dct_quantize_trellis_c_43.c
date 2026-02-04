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
for (i = survivor[0]; i <= last_non_zero + 1; i++) {
    int score = score_tab[i];
    if (!i) continue;
    score += lambda * 2;
    if (score >= last_score) continue;
    last_score = score;
    last_i = i;
    last_level = level_tab[i];
    last_run = run_tab[i];
}
}
