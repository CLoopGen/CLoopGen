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
    for (r = 0; r < stackp && stackp > 0; r++) {
        active[entry->stack[r]] = 5;
        if (r + 1 < stackp)
            active[entry->stack[r + 1]] = 5;
    }
}
