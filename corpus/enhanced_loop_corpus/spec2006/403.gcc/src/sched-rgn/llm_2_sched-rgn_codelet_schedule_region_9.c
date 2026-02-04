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
extern int *edge_to_bit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of iterating sequentially from 1 to nr_edges, we process edges with a stride of 2
    // This changes the memory access pattern to every second element, potentially improving cache behavior
    // in certain scenarios or exposing parallelism.
    for (i = 1; i < nr_edges; i += 2)
        if ((containing_rgn[(edge_table[i].from_block)]) == rgn)
            (edge_to_bit[i]) = rgn_nr_edges++;
    // Process remaining odd index if nr_edges is even
    if (nr_edges % 2 == 0 && (containing_rgn[(edge_table[nr_edges-1].from_block)]) == rgn)
        (edge_to_bit[nr_edges-1]) = rgn_nr_edges++;
}
