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
    int local_count = 0;
    for (i = 1; i < nr_edges; i++) {
        int from_blk = edge_table[i].from_block;
        int crgn = containing_rgn[from_blk];
        if (crgn == rgn) {
            edge_to_bit[i] = local_count;
            local_count++;
        }
    }
    rgn_nr_edges += local_count;
}
