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

typedef struct node node_t;

network_t *net;
node_t *node;
void *stop;

#define DATA_SIZE_MB 64
#define NODE_COUNT ((DATA_SIZE_MB * 1024 * 1024) / sizeof(struct node))

static struct node *nodes_buffer;
static struct arc *arcs_buffer;

void init_vars() {
    size_t node_size = sizeof(struct node);
    size_t arc_size = sizeof(struct arc);
    size_t total_node_bytes = NODE_COUNT * node_size;
    size_t total_arc_bytes = NODE_COUNT * arc_size;

    nodes_buffer = aligned_alloc(64, total_node_bytes);
    arcs_buffer = aligned_alloc(64, total_arc_bytes);

    if (!nodes_buffer || !arcs_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    memset(nodes_buffer, 0, total_node_bytes);
    memset(arcs_buffer, 0, total_arc_bytes);

    net = (network_t*)aligned_alloc(64, sizeof(network_t));
    if (!net) {
        fprintf(stderr, "Failed to allocate network\n");
        exit(1);
    }

    memset(net, 0, sizeof(network_t));
    net->n = NODE_COUNT;
    net->nodes = nodes_buffer;
    net->stop_nodes = nodes_buffer + NODE_COUNT;

    for (long i = 0; i < NODE_COUNT; i++) {
        struct node* nd = &nodes_buffer[i];
        struct arc* ac = &arcs_buffer[i];

        nd->basic_arc = ac;
        nd->flow = (flow_t)(i * 7 + 1);
        nd->potential = i * 13;
        nd->number = (int)i;
        nd->depth = i % 100;

        ac->flow = 0;
        ac->cost = i * 17;
        ac->org_cost = i * 19;
        ac->ident = (int)i;
    }

    net->arcs = arcs_buffer;
    net->stop_arcs = arcs_buffer + NODE_COUNT;

    net->dummy_arcs = NULL;
    net->stop_dummy = NULL;

    net->iterations = 0;
    net->bound_exchanges = 0;
    net->checksum = 0;

    net->feasible = 1;
    net->perturbed = 0;

    strcpy(net->inputfile, "generated_input.dat");
    strcpy(net->clustfile, "generated_cluster.dat");

    node = net->nodes;
    stop = net->stop_nodes;
}