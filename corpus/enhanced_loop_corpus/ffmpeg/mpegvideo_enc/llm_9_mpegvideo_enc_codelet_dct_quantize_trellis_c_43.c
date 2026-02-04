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
    int score = score_tab[i] + ((i != 0) ? lambda * 2 : 0);
    int next_i = i + 1;
    if (next_i <= last_non_zero + 1) {
        int score_next = score_tab[next_i] + lambda * 2;
        if (score_next < last_score) {
            last_score = score_next;
            last_i = next_i;
            last_level = level_tab[next_i];
            last_run = run_tab[next_i];
        }
    }
    if (score < last_score) {
        last_score = score;
        last_i = i;
        last_level = level_tab[i];
        last_run = run_tab[i];
    }
}
}
