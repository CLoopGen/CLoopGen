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

    int dot_product = deltai[d] * delta_i + deltaj[d] * delta_j;
    int condition = (!safe[neighbor] && (dot_product > 0 || queue_start == 1));

    if (!condition) continue;

    int contribution;
    int permeability = permeability_array[ii];

    // Eliminate conditional with false predicate (original had if(0)) -> no effect
    // Removed dead code block entirely

    contribution = (current_strength * permeability) >> 12;

    if (queue_start != 1) {
        contribution = (contribution * dot_product * dot_product) >> 12;
        contribution = (b * contribution) >> 12;
    }

    if (contribution <= ((int)(0.02 * (1 << 12)) + 0.5)) continue;

    if (working[neighbor] == 0) {
        queue[queue_end] = neighbor;
        queue_end++;
    }
    working[neighbor] += contribution;
}
}
