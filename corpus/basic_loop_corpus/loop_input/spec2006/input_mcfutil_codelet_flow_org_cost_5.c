#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

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

typedef struct arc arc_t;

network_t *net;
arc_t *arc;
void *stop;

static node_p nodes_array;
static arc_p arcs_array;

void init_vars() {
    const long num_nodes = 10000;
    const long num_arcs = 200000; // ~1.6MB of arc data

    // Allocate nodes
    nodes_array = (node_p)calloc(num_nodes, sizeof(struct node));
    if (!nodes_array) exit(1);

    // Allocate arcs
    arcs_array = (arc_p)calloc(num_arcs, sizeof(struct arc));
    if (!arcs_array) exit(1);

    // Initialize network structure
    net = (network_t *)calloc(1, sizeof(network_t));
    if (!net) exit(1);

    net->n = num_nodes;
    net->m = num_arcs;
    net->m_org = num_arcs;
    net->eps = (long)(1e-6);
    net->opt_tol = (long)(1e-6);
    net->feas_tol = (long)(1e-6);
    net->pert_val = 1000;
    net->bigM = 1000000;
    net->optcost = 0.0;
    net->ignore_impl = 1;
    net->iterations = 0;
    net->bound_exchanges = 0;
    net->checksum = 0;

    // Set node pointers
    net->nodes = nodes_array;
    net->stop_nodes = nodes_array + num_nodes;

    // Set arc pointers
    net->arcs = arcs_array;
    net->stop_arcs = arcs_array + num_arcs;
    stop = net->stop_arcs;

    // Initialize arc data
    for (long i = 0; i < num_arcs; i++) {
        arcs_array[i].ident = (i % 3 == 0) ? 2 : 1; // every third arc has ident=2
        arcs_array[i].flow = 0;
        arcs_array[i].cost = i * 10;
        arcs_array[i].org_cost = i * 10;
        // Link to dummy nodes
        arcs_array[i].tail = &nodes_array[i % num_nodes];
        arcs_array[i].head = &nodes_array[(i + 1) % num_nodes];
        arcs_array[i].nextout = NULL;
        arcs_array[i].nextin = NULL;
    }

    // Initialize nodes
    for (long i = 0; i < num_nodes; i++) {
        nodes_array[i].number = i;
        nodes_array[i].potential = i * 5;
        nodes_array[i].flow = 0;
        nodes_array[i].depth = i % 100;
        nodes_array[i].orientation = 0;
        nodes_array[i].child = NULL;
        nodes_array[i].pred = NULL;
        nodes_array[i].sibling = NULL;
        nodes_array[i].sibling_prev = NULL;
        nodes_array[i].basic_arc = NULL;
        nodes_array[i].firstout = NULL;
        nodes_array[i].firstin = NULL;
        nodes_array[i].arc_tmp = NULL;
        nodes_array[i].time = 0;
    }
}