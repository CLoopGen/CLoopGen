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


extern  struct hist_node *hist;
extern int i;
extern int j;
extern int k;
extern struct color_ref **refs;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access via Index Mapping
    // Use an auxiliary index array to access entries in reverse order per node,
    // creating an indirect and reversed access pattern.
    for (j = 0; j < (1 << (3 * 5)); j++) {
        const struct hist_node *node = &hist[j];
        // Traverse entries in reverse order using indirect indexing
        for (i = node->nb_entries - 1; i >= 0; i--)
            refs[k++] = &node->entries[i];
    }
}
