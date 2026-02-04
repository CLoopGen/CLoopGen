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


extern struct reading_cache persistent_reading_cache[100];
extern int persistent_reading_cache_size;
extern int k;
extern int sum_nodes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < persistent_reading_cache_size; k++) {
    if (persistent_reading_cache[k].boardsize == 0)
        continue;
    sum_nodes += persistent_reading_cache[k].nodes;
}
}
