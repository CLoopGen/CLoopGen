#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int stackp;
char active[400];
int r;
struct reading_cache *entry;

void init_vars() {
    stackp = 5;
    memset(active, 0, sizeof(active));
    r = 0;
    entry = (struct reading_cache *)calloc(1, sizeof(struct reading_cache));
    if (entry) {
        for (int i = 0; i < 5; i++) {
            entry->stack[i] = i * 80; // Ensure indices are within [0, 399]
        }
    }
}