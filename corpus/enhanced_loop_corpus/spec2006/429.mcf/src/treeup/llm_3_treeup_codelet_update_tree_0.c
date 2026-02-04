#include <stdio.h>

#include <inttypes.h>

typedef long flow_t;

typedef long cost_t;

typedef struct node *node_p;

typedef struct arc *arc_p;

struct arc {
    cost_t cost;
    node_p tail;
    node_p head;
    int ident;
    arc_p nextout;
    arc_p nextin;
    flow_t flow;
    cost_t org_cost;
};


struct node {
    cost_t potential;
    int orientation;
    node_p child;
    node_p pred;
    node_p sibling;
    node_p sibling_prev;
    arc_p basic_arc;
    arc_p firstout;
    arc_p firstin;
    arc_p arc_tmp;
    flow_t flow;
    long depth;
    int number;
    int time;
};


typedef struct node node_t;

extern long cycle_ori;
extern flow_t delta;
extern node_t *jminus;
extern node_t *w;
extern node_t *temp;
extern long depth_iminus;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect access via an array of node pointers built on-the-fly
    // Pre-traverse the path from jminus to w and store nodes in an array,
    // then perform updates through indexed access (indirect memory access pattern)

    node_p path[1000];  // Assume maximum path length; in practice, dynamic allocation may be needed
    int count = 0;
    node_p curr;

    // Build the path array by traversing from jminus up to (but not including) w
    for (curr = jminus; curr != w && count < 999; curr = curr->pred) {
        path[count++] = curr;
    }

    // Now process the array with indirect indexed access
    for (int i = 0; i < count; i++) {
        path[i]->depth -= depth_iminus;
        if (path[i]->orientation != cycle_ori)
            path[i]->flow += delta;
        else
            path[i]->flow -= delta;
    }
}
