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
    // Variant 1: Increased computational intensity with additional arithmetic and unrolled accumulation
    sum_nodes = 0;
    int i;
    for (i = 0; i < persistent_reading_cache_size; i += 4) {
        sum_nodes += persistent_reading_cache[i].nodes;
        if (i + 1 < persistent_reading_cache_size)
            sum_nodes += persistent_reading_cache[i+1].nodes;
        if (i + 2 < persistent_reading_cache_size)
            sum_nodes += persistent_reading_cache[i+2].nodes;
        if (i + 3 < persistent_reading_cache_size)
            sum_nodes += persistent_reading_cache[i+3].nodes;
    }
}
