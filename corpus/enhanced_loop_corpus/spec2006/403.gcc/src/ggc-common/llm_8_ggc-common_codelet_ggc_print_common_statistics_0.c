#include <stdio.h>

#include <inttypes.h>

typedef struct ggc_statistics {
    unsigned int num_trees[256];
    size_t size_trees[256];
    unsigned int num_rtxs[256];
    size_t size_rtxs[256];
    size_t total_size_trees;
    size_t total_size_rtxs;
    unsigned int total_num_trees;
    unsigned int total_num_rtxs;
} ggc_statistics;

extern ggc_statistics *stats;
extern int code;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled loop (partial unrolling by 4)
    // This reduces loop overhead and increases arithmetic operations per iteration
    int code;
    for (code = 0; code < 256; code += 4) {
        stats->total_num_trees += stats->num_trees[code] + stats->num_trees[code+1] +
                                  stats->num_trees[code+2] + stats->num_trees[code+3];
        stats->total_size_trees += stats->size_trees[code] + stats->size_trees[code+1] +
                                   stats->size_trees[code+2] + stats->size_trees[code+3];
    }
}
