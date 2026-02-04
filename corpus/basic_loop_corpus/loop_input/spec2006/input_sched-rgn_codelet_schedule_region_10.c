#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct {
    int from_block;
    int to_block;
    int next_in;
    int next_out;
} haifa_edge;

haifa_edge *edge_table;
int nr_edges = 0;
int rgn = 0;
int i = 0;
int *containing_rgn;
int rgn_nr_edges = 0;
int *rgn_edges;

void init_vars() {
    const int data_size = 1 << 20; // ~8MB for edge_table, ~4MB for containing_rgn, ~4MB for rgn_edges (upper bound)
    nr_edges = data_size;
    rgn = 5;

    edge_table = (haifa_edge*)calloc(nr_edges, sizeof(haifa_edge));
    containing_rgn = (int*)calloc(nr_edges, sizeof(int));
    rgn_edges = (int*)malloc(nr_edges * sizeof(int));

    for (int idx = 0; idx < nr_edges; idx++) {
        edge_table[idx].from_block = idx % (nr_edges / 10);
        containing_rgn[idx] = (idx % 7 == 0) ? rgn : (idx % 7);
    }

    rgn_nr_edges = 0;
    i = 0;
}