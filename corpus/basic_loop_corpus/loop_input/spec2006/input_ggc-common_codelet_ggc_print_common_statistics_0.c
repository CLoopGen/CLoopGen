#include <stdio.h>
#include <stdlib.h>
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

ggc_statistics *stats;
int code;

void init_vars() {
    stats = (ggc_statistics *)calloc(1, sizeof(ggc_statistics));
    if (!stats) {
        exit(1);
    }

    for (int i = 0; i < 256; ++i) {
        stats->num_trees[i] = i + 1;
        stats->size_trees[i] = (i + 1) * 1024;
    }

    stats->total_size_trees = 0;
    stats->total_size_rtxs = 0;
    stats->total_num_trees = 0;
    stats->total_num_rtxs = 0;
}