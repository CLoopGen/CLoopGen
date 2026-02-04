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



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing every element sequentially, traverse with a stride of 2,
    // then handle remaining elements in a second pass to ensure all are processed.
    int stride = 2;
    int i;
    
    // First pass: process elements with stride
    for (i = 0; i < persistent_owl_cache_size; i += stride) {
        sum_tactical_nodes += persistent_owl_cache[i].tactical_nodes;
    }
    
    // Second pass: handle any odd-indexed elements if size is odd
    for (i = 1; i < persistent_owl_cache_size; i += stride) {
        sum_tactical_nodes += persistent_owl_cache[i].tactical_nodes;
    }
}
