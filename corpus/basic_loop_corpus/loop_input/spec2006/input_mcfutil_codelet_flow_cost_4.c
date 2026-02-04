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

static network_t net_instance;
static arc_t* arc_array;
static node_p node_array;

network_t *net = &net_instance;
arc_t *arc = NULL;
void *stop = NULL;
long fleet = 0;
cost_t operational_cost = 0;

void init_vars() {
    const size_t num_nodes = 100000;
    const size_t num_arcs = 200000;

    node_array = (node_p)calloc(num_nodes, sizeof(struct node));
    arc_array = (arc_p)calloc(num_arcs, sizeof(struct arc));

    if (!node_array || !arc_array) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    net = &net_instance;
    net->arcs = arc_array;
    net->nodes = node_array;
    net->stop_nodes = node_array + num_nodes;
    net->stop_arcs = arc_array + num_arcs;
    net->bigM = 1000000L;
    net->m = num_arcs;
    net->n = num_nodes;

    for (size_t i = 0; i < num_nodes; i++) {
        node_array[i].number = (i % 3) - 1;
        node_array[i].potential = i * 10;
        node_array[i].flow = 0;
        node_array[i].depth = i % 100;
        node_array[i].time = i % 50;
        node_array[i].orientation = 0;
        node_array[i].child = NULL;
        node_array[i].pred = NULL;
        node_array[i].sibling = NULL;
        node_array[i].sibling_prev = NULL;
        node_array[i].basic_arc = NULL;
        node_array[i].firstout = NULL;
        node_array[i].firstin = NULL;
        node_array[i].arc_tmp = NULL;
    }

    for (size_t i = 0; i < num_arcs; i++) {
        arc_array[i].cost = (i % 50) + 1;
        arc_array[i].org_cost = arc_array[i].cost;
        arc_array[i].flow = (i % 7) ? 1 : 0;
        arc_array[i].ident = i;
        arc_array[i].nextout = NULL;
        arc_array[i].nextin = NULL;

        size_t tail_idx = i % num_nodes;
        size_t head_idx = (i + 1) % num_nodes;
        arc_array[i].tail = &node_array[tail_idx];
        arc_array[i].head = &node_array[head_idx];

        if (i == 0) {
            node_array[tail_idx].firstout = &arc_array[i];
            node_array[head_idx].firstin = &arc_array[i];
        }
    }

    arc = net->arcs;
    stop = net->stop_arcs;
    fleet = 0;
    operational_cost = 0;
}