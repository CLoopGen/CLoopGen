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
    // Variant 2: Indirect Memory Access via Index Remapping (reverse access pattern)
    int* index_map = alloca((last_non_zero + 2) * sizeof(int));
    int map_size = 0;
    for (int j = last_non_zero + 1; j >= survivor[0]; j--) {
        index_map[map_size++] = j;
    }
    for (int k = 0; k < map_size; k++) {
        i = index_map[k];
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
