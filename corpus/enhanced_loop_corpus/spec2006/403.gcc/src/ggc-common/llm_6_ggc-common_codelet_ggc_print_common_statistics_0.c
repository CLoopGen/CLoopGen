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
    unsigned int temp_num = 0;
    size_t temp_size = 0;
    for (code = 0; code < 256; ++code) {
        temp_num += stats->num_trees[code];
        temp_size += stats->size_trees[code];
    }
    stats->total_num_trees = temp_num;
    stats->total_size_trees = temp_size;
}
