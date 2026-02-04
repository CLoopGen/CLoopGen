#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int from_block;
    int to_block;
    int next_in;
    int next_out;
} haifa_edge;

extern haifa_edge *edge_table;
extern int nr_edges;
extern int rgn;
extern int i;
extern int *containing_rgn;
extern int rgn_nr_edges;
extern int *rgn_edges;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of iterating sequentially by 1, we use a stride of 2 to create strided access.
    // We still process all valid indices by handling even and odd increments within bounds.
    rgn_nr_edges = 0; // Reset counter for correctness
    for (i = 1; i < nr_edges; i += 2) {
        if ((containing_rgn[(edge_table[i].from_block)]) == (rgn))
            rgn_edges[rgn_nr_edges++] = i;
    }
    for (i = 2; i < nr_edges; i += 2) {
        if ((containing_rgn[(edge_table[i].from_block)]) == (rgn))
            rgn_edges[rgn_nr_edges++] = i;
    }
}
