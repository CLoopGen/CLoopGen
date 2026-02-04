#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern char active[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 21; k < 361; k += 2) {
        int neighbor_offsets[4] = {20, -1, -20, 1};
        char base_condition = (board[k] == 3) || (active[k] != 0);
        if (base_condition)
            goto skip_update1;

        for (int nk = 0; nk < 4; nk++) {
            int idx = k + neighbor_offsets[nk];
            if ((board[idx] != 3) && active[idx] > 0 && active[idx] < 4) {
                active[k] = 4;
                break;
            }
        }
skip_update1:;

        // Introduce WAR dependency by updating a future-accessed element early
        if (k + 1 < 361 && board[k + 1] == 3 && active[k + 1] == 0) {
            active[k + 1] = 1;  // Artificially introduce write-before-read (WAR-like) with next iteration
        }
    }

    // Second forward pass to maintain correctness on overlapping indices
    for (k = 22; k < 400; k++) {
        if (k % 2 == 0) continue; // Only process odd indices in second pass

        if (!(board[k] != 3) || active[k] != 0)
            continue;

        if (((board[k + 20] != 3) && active[k + 20] > 0 && active[k + 20] < 4) ||
            ((board[k - 1] != 3) && active[k - 1] > 0 && active[k - 1] < 4) ||
            ((board[k - 20] != 3) && active[k - 20] > 0 && active[k - 20] < 4) ||
            ((board[k + 1] != 3) && active[k + 1] > 0 && active[k + 1] < 4)) {
            active[k] = 4;
        }
    }
}
