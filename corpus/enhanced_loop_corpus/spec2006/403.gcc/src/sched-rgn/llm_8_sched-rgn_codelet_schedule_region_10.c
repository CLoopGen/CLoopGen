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
    int j;
    rgn_nr_edges = 0; // Reset edge counter
    for (i = 0; i < nr_edges; i += 2) {
        if ((containing_rgn[(edge_table[i].from_block)]) == rgn)
            rgn_edges[rgn_nr_edges++] = i;
        if (i + 1 < nr_edges && (containing_rgn[(edge_table[i+1].from_block)]) == rgn)
            rgn_edges[rgn_nr_edges++] = i + 1;
    }
    // Handle odd-sized edge table
    if (nr_edges % 2 == 1 && (containing_rgn[(edge_table[nr_edges-1].from_block)]) == rgn)
        rgn_edges[rgn_nr_edges++] = nr_edges - 1;
}
