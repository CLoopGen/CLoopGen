#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

Intersection board[421];
char active[400];
int k;
struct reading_cache *entry;

void init_vars() {
    entry = (struct reading_cache*)malloc(sizeof(struct reading_cache));
    if (!entry) return;
    entry->boardsize = 19;
    memset(entry->board, 0, sizeof(entry->board));
    entry->movenum = 0;
    entry->nodes = 0;
    entry->score = 0;
    entry->remaining_depth = 0;
    entry->routine = 0;
    entry->str = 0;
    entry->result = 0;
    entry->move = 0;
    for (int i = 0; i < 5; i++) {
        entry->stack[i] = 0;
        entry->move_color[i] = 0;
    }
    for (int i = 0; i < 421; i++) {
        board[i] = (i >= (19 + 2) && i < (19 + 1) * (19 + 1)) ? 3 : 0;
    }
    for (int i = 0; i < 400; i++) {
        active[i] = (i >= (19 + 2) && i < (19 + 1) * (19 + 1)) ? 1 : 0;
    }
    k = 0;
}