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
    int temp_rgn = rgn;
    int temp_edges = rgn_nr_edges;
    for (i = 1; i < nr_edges; i++) {
        int from = edge_table[i].from_block;
        if ((containing_rgn[from]) == temp_rgn) {
            edge_to_bit[i] = temp_edges;
            temp_edges++;
        }
    }
    rgn_nr_edges = temp_edges;
}
