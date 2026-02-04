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
for (code = 0; code < 256; ++code) {
    stats->total_num_trees += stats->num_trees[code];
    stats->total_size_trees += stats->size_trees[code];
}

}
