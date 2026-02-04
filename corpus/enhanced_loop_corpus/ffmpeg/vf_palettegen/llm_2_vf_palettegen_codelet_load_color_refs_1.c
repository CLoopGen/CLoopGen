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
    // Variant 1: Strided Memory Access Pattern
    // Instead of processing entries in natural order, access them with a stride of 2,
    // handling odd and even indices in separate passes to create non-consecutive access.
    for (j = 0; j < (1 << (3 * 5)); j++) {
        const struct hist_node *node = &hist[j];
        // First pass: even indices
        for (i = 0; i < node->nb_entries; i += 2)
            refs[k++] = &node->entries[i];
        // Second pass: odd indices
        for (i = 1; i < node->nb_entries; i += 2)
            refs[k++] = &node->entries[i];
    }
}
