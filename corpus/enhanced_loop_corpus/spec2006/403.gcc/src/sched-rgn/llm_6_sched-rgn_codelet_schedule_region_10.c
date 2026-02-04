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
    int temp_rgn_nr_edges = rgn_nr_edges;
    for (i = 1; i < nr_edges; i++) {
        int from_rgn = containing_rgn[edge_table[i].from_block];
        if (from_rgn == rgn) {
            rgn_edges[temp_rgn_nr_edges] = i;
            temp_rgn_nr_edges++;
        }
    }
    rgn_nr_edges = temp_rgn_nr_edges;
}
