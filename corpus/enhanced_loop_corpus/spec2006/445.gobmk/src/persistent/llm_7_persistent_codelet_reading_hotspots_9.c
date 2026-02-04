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



void loop() {
    sum_nodes = 0;
    for (int i = 0; i < persistent_reading_cache_size; i += 2) {
        int local_sum1 = persistent_reading_cache[i].nodes;
        int local_sum2 = (i + 1 < persistent_reading_cache_size) ? persistent_reading_cache[i + 1].nodes : 0;
        sum_nodes += local_sum1 + local_sum2;
    }
}
