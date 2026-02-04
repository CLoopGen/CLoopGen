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
    // Variant 2: Reduced trip count with stride and conditional scoring impact
    sum_nodes = 0;
    int step = (persistent_reading_cache_size > 20) ? 3 : 1; // Adjust stride based on size
    int j;
    for (j = 0; j < persistent_reading_cache_size; j += step) {
        const struct reading_cache* cache = &persistent_reading_cache[j];
        int bonus = (cache->remaining_depth > 5) ? cache->score : 0;
        sum_nodes += cache->nodes + bonus;
    }
}
