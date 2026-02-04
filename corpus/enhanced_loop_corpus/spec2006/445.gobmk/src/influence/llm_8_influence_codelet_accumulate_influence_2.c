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
    for (d = 0; d < 8; d += 2) {
        int neighbor = ii + delta[d];
        if (board[neighbor] == 3) continue;

        if (!safe[neighbor]) {
            int dot_product = deltai[d] * delta_i + deltaj[d] * delta_j;
            if (dot_product > 0 || queue_start == 1) {
                int permeability = permeability_array[ii];
                int contribution = (current_strength * permeability) >> 12;

                if (queue_start != 1) {
                    contribution = (contribution * dot_product * dot_product) >> 12;
                    contribution = (b * contribution) >> 12;
                }

                int threshold = (int)(0.02 * (1 << 12) + 0.5);
                if (contribution <= threshold) continue;

                if (working[neighbor] == 0) {
                    queue[queue_end++] = neighbor;
                }
                working[neighbor] += contribution;
            }
        }
    }
}
