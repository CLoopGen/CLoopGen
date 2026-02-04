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
    // Strided memory access pattern: unroll and reorganize access to board and safe with stride simulation
    int indices[4];
    int valid[4] = {0};
    int directions[4] = {0, 1, 2, 3};

    // Precompute neighbor indices and validity
    for (d = 0; d < 4; d++) {
        indices[d] = ii + delta[directions[d]];
        if (board[indices[d]] != 3) {
            if (!safe[indices[d]] && (deltai[directions[d]] * delta_i + deltaj[directions[d]] * delta_j > 0 || queue_start == 1)) {
                valid[d] = 1;
            }
        }
    }

    // Process each valid direction with strided array usage
    for (d = 0; d < 4; d++) {
        if (!valid[d]) continue;

        int neighbor = indices[d];
        int di = deltai[directions[d]];
        int dj = deltaj[directions[d]];
        int a = di * delta_i + dj * delta_j;
        int contribution = (current_strength * permeability_array[ii]) >> 12;

        if (queue_start != 1) {
            contribution = (contribution * a * a) >> 12;
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
