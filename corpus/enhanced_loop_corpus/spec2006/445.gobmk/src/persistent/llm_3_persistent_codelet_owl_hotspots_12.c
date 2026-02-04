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
    // Variant 2: Indirect Access via Index Array
    // Use an auxiliary index array to access the cache entries indirectly.
    // This simulates scenarios where access patterns are data-dependent or reordered.
    static int indices[150];
    int i;

    // Initialize index array to identity mapping (could be randomized or sorted in real use)
    for (i = 0; i < persistent_owl_cache_size; i++) {
        indices[i] = i;
    }

    // Traverse using indirect addressing through the index array
    for (i = 0; i < persistent_owl_cache_size; i++) {
        sum_tactical_nodes += persistent_owl_cache[indices[i]].tactical_nodes;
    }
}
