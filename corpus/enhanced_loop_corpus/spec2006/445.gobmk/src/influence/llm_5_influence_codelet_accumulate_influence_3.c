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
    if (board[ii + delta[d]] != 3) {
        if (!safe[ii + delta[d]]) {
            int dir_dot = (deltai[d]) * (delta_i) + (deltaj[d]) * (delta_j);
            if (dir_dot > 0 || queue_start == 1) {
                int permeability = permeability_array[ii];
                int neighbor_i = ii + (deltai[d]) * (19 + 1);
                int neighbor_j = ii + (deltaj[d]);
                int max_neighbor_perm = permeability_array[neighbor_i] > permeability_array[neighbor_j] 
                                      ? permeability_array[neighbor_i] : permeability_array[neighbor_j];
                permeability = (permeability * max_neighbor_perm) >> 12;

                if (permeability > 0) {
                    int contribution = (current_strength * permeability) >> 12;

                    if (queue_start != 1) {
                        contribution = (contribution * dir_dot * dir_dot) >> 12;
                        contribution = (b * contribution) >> 12;
                    }

                    int threshold = (int)(0.02 * (1 << 12) + 0.5);
                    if (contribution > threshold) {
                        if (working[ii + delta[d]] == 0) {
                            queue[queue_end++] = ii + delta[d];
                        }
                        working[ii + delta[d]] += contribution;
                    }
                }
            }
        }
    }
}
}
