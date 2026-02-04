#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int deltai[8];
extern int deltaj[8];
extern int delta[8];
extern Intersection board[421];
extern  int permeability_array[400];
extern  char safe[400];
extern int ii;
extern int queue[400];
extern int d;
extern int b;
extern int queue_start;
extern int queue_end;
extern int working[400];
extern int current_strength;
extern int delta_i;
extern int delta_j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; d < 8; d++) {
        int neighbor_index = ii + delta[d];
        if (board[neighbor_index] == 3) continue;

        int safe_flag = safe[neighbor_index];
        int dot_product = deltai[d] * delta_i + deltaj[d] * delta_j;
        if (safe_flag || (dot_product <= 0 && queue_start != 1)) continue;

        int contribution;
        int permeability = permeability_array[ii];
        int offset_i = deltai[d] * (19 + 1);
        int offset_j = deltaj[d];
        int perm_val_i = permeability_array[ii + offset_i];
        int perm_val_j = permeability_array[ii + offset_j];
        int max_perm = (perm_val_i < perm_val_j) ? perm_val_j : perm_val_i;
        permeability = (permeability * max_perm) >> 12;

        if (permeability == 0) continue;

        contribution = (current_strength * permeability) >> 12;

        if (queue_start != 1) {
            int a = dot_product;
            contribution *= (a * a);
            contribution = (b * contribution) >> 12;
        }

        int threshold = (int)(0.02 * (1 << 12) + 0.5);
        if (contribution <= threshold) continue;

        if (working[neighbor_index] == 0) {
            queue[queue_end] = neighbor_index;
            queue_end++;
        }
        working[neighbor_index] += contribution;
    }
}
