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
    int local_queue[8];
    int local_queue_size = 0;
    int temp_working[8];

    for (int d_local = 0; d_local < 8; d_local++) {
        temp_working[d_local] = 0;
        if (board[ii + delta[d_local]] == 3) {
            continue;
        }

        int neighbor = ii + delta[d_local];
        if (safe[neighbor]) {
            continue;
        }

        int dot_prod = deltai[d_local] * delta_i + deltaj[d_local] * delta_j;
        if (!(dot_prod > 0 || queue_start == 1)) {
            continue;
        }

        int base_perm = permeability_array[ii];
        int perm_i = permeability_array[ii + deltai[d_local] * 20];
        int perm_j = permeability_array[ii + deltaj[d_local]];
        int effective_perm = (perm_i < perm_j) ? perm_j : perm_i;
        int scaled_perm = (base_perm * effective_perm) >> 12;
        if (scaled_perm == 0) continue;

        int contrib = (current_strength * scaled_perm) >> 12;

        if (queue_start != 1) {
            int factor = dot_prod * dot_prod;
            contrib = (contrib * factor) >> 12;
            contrib = (b * contrib) >> 12;
        }

        if (contrib <= ((int)(0.02 * (1 << 12)) + 0.5)) continue;

        temp_working[d_local] = contrib;
        local_queue[local_queue_size++] = neighbor;
    }

    for (int i = 0; i < 8; i++) {
        if (temp_working[i] != 0) {
            int index = ii + delta[i];
            if (working[index] == 0) {
                queue[queue_end++] = index;
            }
            working[index] += temp_working[i];
        }
    }
}
