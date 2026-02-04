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
int nr_edges = 1 << 20; // ~4MB of edges, ensures ~0.01s runtime
int rgn = 5;
int i;
int *containing_rgn;
int rgn_nr_edges;
int *edge_to_bit;

void init_vars() {
    edge_table = (haifa_edge*)calloc(nr_edges, sizeof(haifa_edge));
    containing_rgn = (int*)calloc(nr_edges, sizeof(int));
    edge_to_bit = (int*)calloc(nr_edges, sizeof(int));

    for (int idx = 0; idx < nr_edges; idx++) {
        edge_table[idx].from_block = idx % 10 == 0 ? 0 : 5; // Ensure some pass the condition
        containing_rgn[idx] = (idx % 10 == 0) ? 0 : 5;
    }

    rgn_nr_edges = 0;
}