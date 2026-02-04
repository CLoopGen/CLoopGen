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
        if (board[ii + delta[d]] == 3) continue;

        int neighbor = ii + delta[d];
        if (safe[neighbor]) continue;

        int dot_product = deltai[d] * delta_i + deltaj[d] * delta_j;
        if (!(dot_product > 0 || queue_start == 1)) continue;

        int permeability = permeability_array[ii];
        int cross_term_i = ii + deltai[d] * (19 + 1);
        int cross_term_j = ii + deltaj[d];
        int max_cross = permeability_array[cross_term_i] < permeability_array[cross_term_j] ?
                        permeability_array[cross_term_j] : permeability_array[cross_term_i];
        permeability = (permeability * max_cross) >> 12;
        if (permeability == 0) continue;

        int contribution = (current_strength * permeability) >> 12;

        if (queue_start != 1) {
            contribution = (contribution * (dot_product * dot_product)) >> 12;
            contribution = (b * contribution) >> 12;
        }

        if (contribution <= ((int)(0.02 * (1 << 12)) + 0.5)) continue;

        if (working[neighbor] == 0) {
            queue[queue_end++] = neighbor;
        }
        working[neighbor] += contribution;
    }
}
