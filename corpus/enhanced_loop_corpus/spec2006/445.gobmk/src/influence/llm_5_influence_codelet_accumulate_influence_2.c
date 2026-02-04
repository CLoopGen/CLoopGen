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
    if ((board[ii + delta[d]] != 3)) {
        if (!safe[ii + delta[d]]) {
            int dot_product = (deltai[d]) * (delta_i) + (deltaj[d]) * (delta_j);
            if (dot_product > 0 || queue_start == 1) {
                int permeability = permeability_array[ii];
                int contribution = (current_strength * permeability) >> 12;

                if (queue_start != 1) {
                    contribution = (contribution * dot_product * dot_product * b) >> 12;
                }

                if (contribution > ((int)(0.02 * (1 << 12)) + 0.5)) {
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
