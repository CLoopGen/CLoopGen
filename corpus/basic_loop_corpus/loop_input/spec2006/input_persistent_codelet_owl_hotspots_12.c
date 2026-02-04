#include <stdio.h>
#include <inttypes.h>

struct owl_cache {
    int boardsize;
    char board[400];
    int movenum;
    int tactical_nodes;
    int routine;
    int apos;
    int bpos;
    int cpos;
    int result;
    int result_certain;
    int move;
    int move2;
};

#define PERSISTENT_OWL_CACHE_SIZE 100000

struct owl_cache persistent_owl_cache[150];
int persistent_owl_cache_size;
int k;
int sum_tactical_nodes;

void init_vars() {
    persistent_owl_cache_size = 150;
    sum_tactical_nodes = 0;
    for (int i = 0; i < persistent_owl_cache_size; i++) {
        persistent_owl_cache[i].boardsize = 19;
        for (int j = 0; j < 400; j++) {
            persistent_owl_cache[i].board[j] = (char)(j % 256);
        }
        persistent_owl_cache[i].movenum = i;
        persistent_owl_cache[i].tactical_nodes = (i * 7) % 1000;
        persistent_owl_cache[i].routine = i % 3;
        persistent_owl_cache[i].apos = (i + 1) * 10;
        persistent_owl_cache[i].bpos = (i + 1) * 20;
        persistent_owl_cache[i].cpos = (i + 1) * 30;
        persistent_owl_cache[i].result = i % 2;
        persistent_owl_cache[i].result_certain = (i % 10 == 0);
        persistent_owl_cache[i].move = (i + 5) % 361;
        persistent_owl_cache[i].move2 = (i + 10) % 361;
    }
}