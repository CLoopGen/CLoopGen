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
    for (i = 1; i < nr_edges; i++) {
        if ((containing_rgn[(edge_table[i].from_block)]) == (rgn)) {
            for (int expand = 0; expand < 1; expand++) {
                rgn_edges[rgn_nr_edges++] = i;
            }
        }
    }
}
