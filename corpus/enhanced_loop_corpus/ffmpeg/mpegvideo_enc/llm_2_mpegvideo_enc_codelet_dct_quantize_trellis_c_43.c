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



void loop() {
    // Variant 1: Strided Memory Access (access every 2nd element, then handle remainder)
    int stride = 2;
    last_i = survivor[0];
    // Forward strided pass
    for (i = survivor[0]; i <= last_non_zero + 1; i += stride) {
        int score = score_tab[i];
        if (i)
            score += lambda * 2;
        if (score < last_score) {
            last_score = score;
            last_i = i;
            last_level = level_tab[i];
            last_run = run_tab[i];
        }
    }
    // Handle odd indices if starting survivor[0] is even or stride skips some
    for (i = survivor[0] + 1; i <= last_non_zero + 1; i += stride) {
        int score = score_tab[i];
        if (i)
            score += lambda * 2;
        if (score < last_score) {
            last_score = score;
            last_i = i;
            last_level = level_tab[i];
            last_run = run_tab[i];
        }
    }
}
