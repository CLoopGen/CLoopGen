#include <stdio.h>
#include <stdlib.h>
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

network_t *net;
arc_p arc;
void *stop;

static arc_p arcs_array;
static network_t network_instance;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024 / sizeof(struct arc); // ~64MB to target 0.01s runtime
    arcs_array = (arc_p)calloc(data_size, sizeof(struct arc));
    if (!arcs_array) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        arcs_array[i].ident = (i % 3 == 0) ? 2 : 1;
        arcs_array[i].flow = 0;
    }

    net = &network_instance;
    net->arcs = arcs_array;
    net->m = data_size;

    stop = (void*)&arcs_array[data_size];
    arc = NULL;
}