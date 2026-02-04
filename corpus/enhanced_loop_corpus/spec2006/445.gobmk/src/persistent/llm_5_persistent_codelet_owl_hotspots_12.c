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


extern struct owl_cache persistent_owl_cache[150];
extern int persistent_owl_cache_size;
extern int k;
extern int sum_tactical_nodes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < persistent_owl_cache_size; k++) {
        sum_tactical_nodes += persistent_owl_cache[k].tactical_nodes;
        if (persistent_owl_cache[k].result_certain) {
            break;
        }
    }
}
