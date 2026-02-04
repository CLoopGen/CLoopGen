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
    for (k = (19 + 2); k < (19 + 1) * (19 + 1); k++) {
        entry->board[k] = board[k] != 3 ? (active[k] != 0 ? board[k] : 3) : entry->board[k];
    }
}
