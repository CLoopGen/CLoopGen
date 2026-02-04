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
        for (int unroll_factor = 0; unroll_factor < 1; unroll_factor++) {
            if ((board[ii + delta[d]] != 3)) {
                if (!safe[ii + delta[d]] && ((deltai[d]) * (delta_i) + (deltaj[d]) * (delta_j) > 0 || queue_start == 1)) {
                    int contribution;
                    int permeability = permeability_array[ii];
                    {
                        permeability = ((permeability) * (((permeability_array[ii + ((deltai[d]) * (19 + 1) + (0))]) < (permeability_array[ii + ((0) * (19 + 1) + (deltaj[d]))]) ? (permeability_array[ii + ((0) * (19 + 1) + (deltaj[d]))]) : (permeability_array[ii + ((deltai[d]) * (19 + 1) + (0))]))) / (1 << 12));
                        if (permeability == 0)
                            break;
                    }
                    contribution = ((current_strength) * (permeability) / (1 << 12));
                    if (queue_start != 1) {
                        int a = (deltai[d]) * (delta_i) + (deltaj[d]) * (delta_j);
                        contribution *= (a * a);
                        contribution = ((b) * (contribution) / (1 << 12));
                    }
                    if (contribution <= ((int)((0.02) * (1 << 12)) + 0.5))
                        continue;
                    if (working[ii + delta[d]] == 0) {
                        queue[queue_end] = (ii + delta[d]);
                        queue_end++;
                    }
                    working[ii + delta[d]] += contribution;
                }
            }
        }
    }
}
