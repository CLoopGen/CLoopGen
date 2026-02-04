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
int worst_entry;
int worst_score;

void init_vars() {
    worst_score = 2147483647;
    worst_entry = 0;

    for (int i = 0; i < 100; i++) {
        persistent_reading_cache[i].boardsize = 19;
        for (int j = 0; j < 400; j++) {
            persistent_reading_cache[i].board[j] = (char)(j % 256);
        }
        persistent_reading_cache[i].movenum = i;
        persistent_reading_cache[i].nodes = 1000 + i * 100;
        persistent_reading_cache[i].score = 1000 - i * 10;
        persistent_reading_cache[i].remaining_depth = 5 + (i % 6);
        persistent_reading_cache[i].routine = i % 3;
        persistent_reading_cache[i].str = 0;
        persistent_reading_cache[i].result = i % 2;
        persistent_reading_cache[i].move = 1 + (i * 7) % 361;
        for (int j = 0; j < 5; j++) {
            persistent_reading_cache[i].stack[j] = (i + j) % 100;
            persistent_reading_cache[i].move_color[j] = (i + j) % 2;
        }
    }
}