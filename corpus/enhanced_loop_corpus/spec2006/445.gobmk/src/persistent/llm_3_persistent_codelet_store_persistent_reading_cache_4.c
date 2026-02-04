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
    // Variant 2: Indirect memory access using pointer arithmetic and shuffled order
    // Access the stack indices in reverse order (indirect traversal) to change access pattern
    int index;
    for (index = stackp - 1; index >= 0; index--) {
        int pos = entry->stack[index];
        active[pos] = 5;
    }
}
