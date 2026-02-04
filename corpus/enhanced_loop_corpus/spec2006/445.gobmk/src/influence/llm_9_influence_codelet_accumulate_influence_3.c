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
    int unrolled_d;
    // Unroll the loop to reduce control overhead and increase computational density
    for (unrolled_d = d; unrolled_d < 8; unrolled_d += 4) {
        #pragma unroll
        for (int step = 0; step < 4 && (unrolled_d + step) < 8; step++) {
            int idx = unrolled_d + step;
            if (board[ii + delta[idx]] == 3) continue;

            if (!safe[ii + delta[idx]] && (deltai[idx] * delta_i + deltaj[idx] * delta_j > 0 || queue_start == 1)) {
                int contribution;
                int perm_val_1 = permeability_array[ii + deltai[idx]*(19+1)];
                int perm_val_2 = permeability_array[ii + deltaj[idx]];
                int max_perm = perm_val_1 > perm_val_2 ? perm_val_1 : perm_val_2;
                int permeability = (permeability_array[ii] * max_perm) >> 12;

                if (permeability == 0) continue;

                contribution = (current_strength * permeability) >> 12;

                if (queue_start != 1) {
                    int a = deltai[idx] * delta_i + deltaj[idx] * delta_j;
                    contribution = (contribution * a * a) >> 12;
                    contribution = (b * contribution) >> 12;
                }

                if (contribution <= (int)(0.02 * (1 << 12) + 0.5)) continue;

                int target_index = ii + delta[idx];
                if (working[target_index] == 0) {
                    queue[queue_end] = target_index;
                    queue_end++;
                }
                working[target_index] += contribution;
            }
        }
    }
    d = unrolled_d; // Update outer state if needed
}
