#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef long cost_t;
typedef long flow_t;

struct arc {
    cost_t cost;
    struct node *tail;
    struct node *head;
    int ident;
    struct arc *nextout;
    struct arc *nextin;
    flow_t flow;
    cost_t org_cost;
};

struct node {
    cost_t potential;
    int orientation;
    struct node *child;
    struct node *pred;
    struct node *sibling;
    struct node *sibling_prev;
    struct arc *basic_arc;
    struct arc *firstout;
    struct arc *firstin;
    struct arc *arc_tmp;
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
    struct node *nodes;
    struct node *stop_nodes;
    struct arc *arcs;
    struct arc *stop_arcs;
    struct arc *dummy_arcs;
    struct arc *stop_dummy;
    long iterations;
    long bound_exchanges;
    long checksum;
} network_t;

network_t *net;
struct arc *arc;
void *stop;
long fleet;
cost_t operational_cost;

#define DATA_SIZE_MB 64
#define NUM_ARCS (DATA_SIZE_MB * 1024 * 1024 / sizeof(struct arc))

static struct node *nodes_pool;
static struct arc *arcs_pool;

void init_vars() {
    net = (network_t *)calloc(1, sizeof(network_t));
    nodes_pool = (struct node *)calloc(NUM_ARCS * 2, sizeof(struct node));
    arcs_pool = (struct arc *)calloc(NUM_ARCS, sizeof(struct arc));

    net->arcs = arcs_pool;
    net->nodes = nodes_pool;
    net->bigM = 100000;
    net->m = NUM_ARCS;

    arc = net->arcs;
    stop = (void *)(net->arcs + NUM_ARCS);

    for (long i = 0; i < NUM_ARCS; i++) {
        struct node *tail = &nodes_pool[i * 2];
        struct node *head = &nodes_pool[i * 2 + 1];

        tail->number = (i % 3 == 0) ? 0 : (i % 7 == 0 ? -1 : 1);
        head->number = (i % 5 == 0) ? 1 : -1;

        arcs_pool[i].tail = tail;
        arcs_pool[i].head = head;
        arcs_pool[i].flow = (i % 4 != 0) ? 1 : 0;
        arcs_pool[i].org_cost = 100 + (i % 50);
    }

    fleet = 0;
    operational_cost = 0;
}