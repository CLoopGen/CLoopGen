#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int dpos;
extern int surrounded;
extern int color;
extern int other;
extern char mf[400];
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int next_dpos = (19 + 2);
    int prev_surrounded = surrounded;
    // Introduce loop-carried dependence via delayed update of 'surrounded'
    for (int i = (19 + 2); i < (19 + 1) * (19 + 1) && prev_surrounded; i++) {
        dpos = next_dpos; // Create WAR hazard: write after read in previous iteration
        next_dpos = i + 1;

        if ((board[dpos] != 3) && mf[dpos]) {
            // Add redundant dependency on 'other' and 'color' through dummy computation
            int neighbor_offsets[4] = { -(19 + 1), (19 + 1), 1, -1 };
            int temp_color = color ^ other; // Artificial RAW dependency
            int trigger = 0;

            for (int j = 0; j < 4 && !trigger; j++) {
                int adj = dpos + neighbor_offsets[j];
                int ext = adj + neighbor_offsets[j]; // Extend in same direction

                if (j < 2) { // Vertical directions: check horizontal neighbors
                    if ((board[adj] != 3) && board[adj] == 0 &&
                        (board[ext] != 3) && board[ext] == temp_color && 
                        mn[ext] != 1 &&
                        (board[adj + 1] != 3) && board[adj + 1] != other &&
                        (board[adj - 1] != 3) && board[adj - 1] != other) {
                        trigger = 1;
                    }
                } else { // Horizontal directions: check vertical neighbors
                    if ((board[adj] != 3) && board[adj] == 0 &&
                        (board[ext] != 3) && board[ext] == temp_color && 
                        mn[ext] != 1 &&
                        (board[adj - (19 + 1)] != 3) && board[adj - (19 + 1)] != other &&
                        (board[adj + (19 + 1)] != 3) && board[adj + (19 + 1)] != other) {
                        trigger = 1;
                    }
                }
            }

            if (trigger) {
                surrounded = 0; // Update only at end to preserve loop-carried dependency
                prev_surrounded = 0;
            }
        }
    }
}
