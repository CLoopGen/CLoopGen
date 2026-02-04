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
extern node_t *jplus;
extern node_t *w;
extern node_t *temp;
extern long depth_iminus;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access Pattern via pointer array
    // Collect all nodes along the path into an array of pointers,
    // then iterate over them using indirect indexing with reversed order access
    // to demonstrate non-sequential memory traversal pattern.

    #define MAX_NODES 1024
    static node_p node_ptrs[MAX_NODES];
    int count = 0;
    node_t* curr;

    // Gather nodes from jplus to w (exclusive of w)
    for (curr = jplus; curr != w && count < MAX_NODES - 1; curr = curr->pred) {
        node_ptrs[count++] = curr;
    }

    // Perform operations using indirect access in reverse order (indirect + reverse stride)
    // This changes spatial locality and creates a different cache access pattern
    for (int i = count - 1; i >= 0; i--) {
        node_p temp = node_ptrs[i];
        temp->depth += depth_iminus;
        if (temp->orientation == cycle_ori)
            temp->flow += delta;
        else
            temp->flow -= delta;
    }
}
