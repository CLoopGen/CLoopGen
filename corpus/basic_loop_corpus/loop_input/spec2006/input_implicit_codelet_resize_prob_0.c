#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long cost_t;
typedef struct node *node_p;
typedef struct arc *arc_p;
typedef long flow_t;

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

typedef struct network {
    char inputfile[200];
    char clustfile[200];
    long n;
    long n_trips;
    long max_m;
    long m;
    long m_org;
    long m_impl;
    long max_residual_new_m;
    long max_new_m;
    long primal_unbounded;
    long dual_unbounded;
    long perturbed;
    long feasible;
    long eps;
    long opt_tol;
    long feas_tol;
    long pert_val;
    long bigM;
    double optcost;
    cost_t ignore_impl;
    node_p nodes;
    node_p stop_nodes;
    arc_p arcs;
    arc_p stop_arcs;
    arc_p dummy_arcs;
    arc_p stop_dummy;
    long iterations;
    long bound_exchanges;
    long checksum;
} network_t;

typedef struct node node_t;
typedef struct arc arc_t;

network_t *net;
node_t *node;
node_t *stop;
node_t *root;
size_t off;

#define NODE_COUNT (1 << 20)  // ~8MB of node data, sufficient for ~0.01s runtime

static node_t nodes_buffer[NODE_COUNT + 1];  // Extra for root and alignment
static arc_t arcs_buffer[NODE_COUNT];

void init_vars() {
    net = (network_t *)calloc(1, sizeof(network_t));
    if (!net) exit(1);

    net->n = NODE_COUNT;
    net->nodes = nodes_buffer;
    net->stop_nodes = nodes_buffer + NODE_COUNT;

    memset(nodes_buffer, 0, sizeof(node_t) * (NODE_COUNT + 1));
    memset(arcs_buffer, 0, sizeof(arc_t) * NODE_COUNT);

    for (long i = 0; i < NODE_COUNT; i++) {
        nodes_buffer[i].pred = &nodes_buffer[i-1];  // Most have valid pred
        nodes_buffer[i].basic_arc = (arc_t *)((size_t)&arcs_buffer[i] + 16);  // Non-null, misaligned base
        nodes_buffer[i].number = i;
    }

    // Set root as pred of first real node
    root = &nodes_buffer[0];
    nodes_buffer[1].pred = root;

    // Make sure other nodes have non-root preds
    for (long i = 2; i < NODE_COUNT; i++) {
        if (i % 7 != 0)  // Occasionally set to root to ensure some are skipped
            nodes_buffer[i].pred = &nodes_buffer[i-2];
    }

    node = &nodes_buffer[1];  // Start from second node
    stop = net->stop_nodes;

    off = 32;  // Arbitrary offset to add
}