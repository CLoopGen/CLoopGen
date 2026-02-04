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
    int temp_sum = 0;
    for (int i = 0; i < persistent_reading_cache_size; i++) {
        temp_sum += persistent_reading_cache[i].nodes;
    }
    sum_nodes = temp_sum;
}
