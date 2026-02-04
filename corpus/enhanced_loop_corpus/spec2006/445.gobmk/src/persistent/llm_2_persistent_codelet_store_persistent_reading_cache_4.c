#include <stdio.h>

#include <inttypes.h>

struct reading_cache {
    int boardsize;
    char board[400];
    int movenum;
    int nodes;
    int score;
    int remaining_depth;
    int routine;
    int str;
    int result;
    int move;
    int stack[5];
    int move_color[5];
};


extern int stackp;
extern char active[400];
extern int r;
extern struct reading_cache *entry;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with unrolling and stride simulation
    // Instead of accessing entry->stack[r] sparsely, we process multiple indices per iteration
    // and write to active with a fixed pattern. This increases spatial locality.
    int limit = stackp;
    int i;
    for (i = 0; i < limit; i += 2) {
        active[entry->stack[i]] = 5;
        if (i + 1 < limit) {
            active[entry->stack[i + 1]] = 5;
        }
    }
}
