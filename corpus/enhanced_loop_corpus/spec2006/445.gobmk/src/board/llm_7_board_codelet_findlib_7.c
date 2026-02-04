#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

struct string_data {
    int color;
    int size;
    int origin;
    int liberties;
    int libs[20];
    int neighbors;
    int neighborlist[160];
    int mark;
};


extern Intersection board[421];
extern struct string_data string[240];
extern int next_stone[400];
extern int ml[400];
extern int liberty_mark;
extern int maxlib;
extern int *libs;
extern int k;
extern int liberties;
extern int s;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Eliminate loop-carried dependence on `k` by precomputing bounds and using temporary index
    int local_k = k; // Break WAW hazard on global `k` until loop end
    int base_pos = string[s].origin;
    int current = base_pos;
    int steps = 0;
    int max_steps = (liberties < maxlib) ? liberties : maxlib;

    for (; steps < max_steps && current != 0; steps++, current = next_stone[current]) {
        // Reorder neighbor checks to change instruction-level dependency chains
        // Introduce WAR-like pattern by deferring global updates
        int offsets[] = {1, -(19+1), -1, (19+1)}; // Changed access order
        for (int o = 0; o < 4; o++) {
            int neighbor_pos = current + offsets[o];
            if ((board[neighbor_pos] == 0) && (ml[neighbor_pos] != liberty_mark)) {
                if (local_k < maxlib) {
                    libs[local_k] = neighbor_pos;
                    ml[neighbor_pos] = liberty_mark; // Update memory early -> creates RAW for subsequent iterations
                    local_k++;
                }
            }
        }
    }
    // Only update global `k` at the end to eliminate loop-carried WAW on `k`
    k = local_k;
}
