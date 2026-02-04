#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct color_ref {
    uint32_t color;
    uint64_t count;
};

struct hist_node {
    struct color_ref *entries;
    int nb_entries;
};

struct hist_node *hist;
int i;
int j;
int k;
struct color_ref **refs;

void init_vars() {
    const int num_nodes = 1 << (3 * 5); // 32768 nodes
    const int avg_entries_per_node = 16;
    const int total_refs = num_nodes * avg_entries_per_node;
    const size_t data_size = total_refs * sizeof(struct color_ref);
    const size_t refs_size = total_refs * sizeof(struct color_ref*);

    hist = calloc(num_nodes, sizeof(struct hist_node));
    refs = malloc(refs_size);

    size_t current_color_index = 0;
    for (int idx = 0; idx < num_nodes; idx++) {
        int nb_entries = avg_entries_per_node;
        struct color_ref *entries = malloc(nb_entries * sizeof(struct color_ref));
        for (int e = 0; e < nb_entries; e++) {
            entries[e].color = (uint32_t)(current_color_index++);
            entries[e].count = 1;
        }
        hist[idx].entries = entries;
        hist[idx].nb_entries = nb_entries;
    }

    k = 0;
}