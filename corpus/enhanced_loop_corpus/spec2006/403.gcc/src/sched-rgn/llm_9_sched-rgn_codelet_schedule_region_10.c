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
    rgn_nr_edges = 0;
    for (i = nr_edges - 1; i >= 1; i--) {
        int from = edge_table[i].from_block;
        int crgn = containing_rgn[from];
        if (crgn == rgn) {
            rgn_edges[rgn_nr_edges] = i;
            rgn_nr_edges += 1;
        }
    }
}
