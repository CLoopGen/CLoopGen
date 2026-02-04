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
    for (d = 0; d < 4; d++) {
        int offset = delta[d];
        int idx = ii + offset;

        if (board[idx] != 3 && !safe[idx]) {
            int dir_factor = deltai[d] * delta_i + deltaj[d] * delta_j;

            if (dir_factor > 0 || queue_start == 1) {
                int perm_val = permeability_array[ii];
                int contrib = (current_strength * perm_val) >> 12;

                if (queue_start != 1) {
                    int squared_dir = dir_factor * dir_factor;
                    contrib = (contrib * squared_dir) >> 12;
                    contrib = (b * contrib) >> 12;
                }

                if (contrib > (int)(0.02 * (1 << 12) + 0.5)) {
                    if (working[idx] == 0) {
                        queue[queue_end] = idx;
                        queue_end++;
                    }
                    working[idx] += contrib;
                }
            }
        }
    }

    // Additional computational pass to increase intensity
    for (int k = 0; k < 4 && queue_start != 1; k++) {
        int temp = (permeability_array[ii] * deltai[k]) >> 10;
        temp = (temp + (permeability_array[ii] * deltaj[k]) >> 10) >> 1;
        if (temp > 10) {
            int probe_idx = ii + delta[k];
            if (probe_idx < 421 && working[probe_idx] == 0) {
                queue[queue_end++] = probe_idx;
                working[probe_idx] = temp;
            }
        }
    }
}
