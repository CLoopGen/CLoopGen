#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

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


extern Intersection board[421];
extern char active[400];
extern int k;
extern struct reading_cache *entry;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_k;
    int step = (19 + 1) * (19 + 1);
    for (outer_k = (19 + 2); outer_k < step; outer_k += step) { // Outer loop with large step to run once
        for (k = outer_k; k < (19 + 1) * (19 + 1) && k < outer_k + step; k++) { // Inner loop does the actual work
            if (!(board[k] != 3))
                continue;
            entry->board[k] = active[k] != 0 ? board[k] : 3;
        }
    }
}
