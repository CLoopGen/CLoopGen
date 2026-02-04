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
static arc_t* arc_ptr = NULL;
static void* stop_ptr = NULL;

network_t *net = &net_instance;
extern arc_t *arc = NULL;
void *stop = NULL;

#define DATA_SIZE_MB 64
#define NUM_ARCS ((DATA_SIZE_MB * (1 << 20)) / sizeof(arc_t))
#define NUM_NODES (NUM_ARCS / 8 + 1)

static arc_t arcs_data[NUM_ARCS];
static struct node nodes_data[NUM_NODES];

void init_vars() {
    memset(&net_instance, 0, sizeof(network_t));
    memset(arcs_data, 0, sizeof(arcs_data));
    memset(nodes_data, 0, sizeof(nodes_data));

    net->n = NUM_NODES;
    net->m = NUM_ARCS;
    net->arcs = arcs_data;
    net->stop_arcs = arcs_data + NUM_ARCS;
    net->nodes = nodes_data;
    net->stop_nodes = nodes_data + NUM_NODES;

    arc_ptr = arcs_data;
    stop_ptr = (void*)net->stop_arcs;
    arc = arcs_data;
    stop = stop_ptr;

    for (long i = 0; i < NUM_ARCS; i++) {
        arcs_data[i].ident = i;
        arcs_data[i].org_cost = i * 7 + 3;
        arcs_data[i].cost = i * 7 + 3;
        arcs_data[i].flow = 0;

        long tail_idx = i % NUM_NODES;
        long head_idx = (i + 1) % NUM_NODES;

        arcs_data[i].tail = &nodes_data[tail_idx];
        arcs_data[i].head = &nodes_data[head_idx];

        arcs_data[i].nextout = NULL;
        arcs_data[i].nextin = NULL;

        nodes_data[tail_idx].number = tail_idx;
        nodes_data[head_idx].number = head_idx;
    }

    for (long i = 0; i < NUM_NODES; i++) {
        nodes_data[i].firstout = NULL;
        nodes_data[i].firstin = NULL;
        nodes_data[i].potential = i * 5;
        nodes_data[i].flow = 0;
        nodes_data[i].depth = i % 10;
        nodes_data[i].time = 0;
        nodes_data[i].orientation = 0;
        nodes_data[i].child = NULL;
        nodes_data[i].pred = NULL;
        nodes_data[i].sibling = NULL;
        nodes_data[i].sibling_prev = NULL;
        nodes_data[i].basic_arc = NULL;
        nodes_data[i].arc_tmp = NULL;
    }
}