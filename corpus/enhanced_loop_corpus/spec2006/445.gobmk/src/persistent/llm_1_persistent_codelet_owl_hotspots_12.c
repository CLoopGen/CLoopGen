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
    if (persistent_owl_cache_size > 0) {
        // Loop unrolled by a factor of 2 for reduced iteration count and increased per-iteration work
        int i = 0;
        for (; i <= persistent_owl_cache_size - 2; i += 2) {
            sum_tactical_nodes += persistent_owl_cache[i].tactical_nodes +
                                  persistent_owl_cache[i+1].tactical_nodes;
        }
        // Handle remaining element if size is odd
        for (; i < persistent_owl_cache_size; i++) {
            sum_tactical_nodes += persistent_owl_cache[i].tactical_nodes;
        }
    }
}
