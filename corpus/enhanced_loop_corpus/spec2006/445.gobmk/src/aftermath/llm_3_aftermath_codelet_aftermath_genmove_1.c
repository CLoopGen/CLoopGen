#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int delta[8];
extern Intersection board[421];
extern int color;
extern int k;
extern int other;
extern int distance[400];
extern int something_found;
extern int closest_opponent;
extern int closest_own;
extern int d;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access via Index Array
    // Use an auxiliary index array to access board[] and distance[] indirectly.
    // This simulates a gather-style access pattern, useful in data-dependent scenarios.
    int indices[400];
    int count = 0;
    // Precompute valid indices within bounds
    for (int i = (19 + 2); i < (19 + 1) * (19 + 1); i++) {
        indices[count++] = i;
    }
    // Traverse using indirect addressing
    for (int idx = 0; idx < count; idx++) {
        pos = indices[idx];
        if ((board[pos] != 3) && distance[pos] == -1) {
            for (k = 0; k < 4; k++) {
                int pos2 = pos + delta[k];
                if (!(board[pos2] != 3))
                    continue;
                if ((d == 0 || board[pos2] == 0) && distance[pos2] == d) {
                    if (d > 0 && board[pos] == other) {
                        distance[pos] = d + 1;
                        if (closest_opponent == 0)
                            closest_opponent = pos;
                    } else if (d > 0 && board[pos] == color) {
                        distance[pos] = d + 1;
                        if (closest_own == 0)
                            closest_own = pos;
                    } else if (board[pos] == 0) {
                        distance[pos] = d + 1;
                        something_found = 1;
                    }
                    break;
                }
            }
        }
    }
}
