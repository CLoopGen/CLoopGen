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



void loop(){
    for (r = stackp - 1; r >= 0; r--) {
        int offset = entry->stack[r];
        active[offset] = 5;
        entry->move_color[r % 5] += entry->score + entry->nodes;
    }
}
