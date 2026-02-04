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

struct reading_cache persistent_reading_cache[100];
int persistent_reading_cache_size = 100;
int k;
int sum_nodes;

void init_vars() {
    for (int i = 0; i < 100; i++) {
        persistent_reading_cache[i].boardsize = 19;
        for (int j = 0; j < 400; j++) {
            persistent_reading_cache[i].board[j] = 0;
        }
        persistent_reading_cache[i].movenum = i;
        persistent_reading_cache[i].nodes = 100000;
        persistent_reading_cache[i].score = i * 5;
        persistent_reading_cache[i].remaining_depth = 5;
        persistent_reading_cache[i].routine = 1;
        persistent_reading_cache[i].str = 0;
        persistent_reading_cache[i].result = 0;
        persistent_reading_cache[i].move = 0;
        for (int j = 0; j < 5; j++) {
            persistent_reading_cache[i].stack[j] = 0;
            persistent_reading_cache[i].move_color[j] = 1 + (i % 2);
        }
    }
    k = 0;
    sum_nodes = 0;
}