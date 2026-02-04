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
        int neighbor = ii + delta[d];
        if (board[neighbor] == 3) continue;

        if (!safe[neighbor] && (deltai[d] * delta_i + deltaj[d] * delta_j > 0 || queue_start == 1)) {
            int contribution;
            int permeability = permeability_array[ii];

            contribution = (current_strength * permeability) >> 12;
            if (queue_start != 1) {
                int a = deltai[d] * delta_i + deltaj[d] * delta_j;
                contribution = (contribution * a * a) >> 12;
                contribution = (b * contribution) >> 12;
            }

            if (contribution <= ((int)(0.02 * (1 << 12)) + 0.5)) continue;

            if (working[neighbor] == 0) {
                queue[queue_end++] = neighbor;
            }
            working[neighbor] += contribution;
        }
    }
}
