#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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
long i;

void init_vars() {
    net = (network_t *)calloc(1, sizeof(network_t));
    
    // Set bigM and tolerance values
    net->bigM = 20000000L;  // Greater than 1e7 to trigger the conditional
    net->opt_tol = 1;
    net->feas_tol = 1;
    net->pert_val = 0;
    net->eps = 1;
    net->primal_unbounded = 0;
    net->dual_unbounded = 0;
    net->perturbed = 0;
    net->feasible = 1;
    net->ignore_impl = 0;
    net->iterations = 0;
    net->bound_exchanges = 0;
    net->checksum = 0;
    net->optcost = 0.0;
    strcpy(net->inputfile, "input.dat");
    strcpy(net->clustfile, "clust.dat");

    // Estimate data size for ~0.01 sec runtime: aim for moderate memory access
    // Each iteration uses 3*i-1, so we need at least 3*n_trips arcs
    // On modern CPU, 100K–1M iterations typical for 0.01s if simple ops
    // Let's target about 150,000 trips => ~450,000 arcs, ~7 MB of arc data
    net->n_trips = 150000L;
    net->n = net->n_trips;
    net->m = 3 * net->n_trips;
    net->m_org = net->m;
    net->m_impl = net->m;
    net->max_m = net->m;
    net->max_new_m = net->m;
    net->max_residual_new_m = net->m;

    // Allocate arcs: index up to 3*n_trips
    net->arcs = (struct arc *)calloc(net->m + 10, sizeof(struct arc));
    net->stop_arcs = &net->arcs[net->m];

    // Allocate nodes
    net->nodes = (struct node *)calloc(net->n + 10, sizeof(struct node));
    net->stop_nodes = &net->nodes[net->n];

    // Initialize dummy pointers
    net->dummy_arcs = NULL;
    net->stop_dummy = NULL;

    // Initialize arc fields to avoid undefined behavior
    for (long idx = 0; idx <= net->m; idx++) {
        net->arcs[idx].cost = 0;
        net->arcs[idx].org_cost = 0;
        net->arcs[idx].flow = 0;
        net->arcs[idx].ident = idx;
        net->arcs[idx].tail = &net->nodes[0];
        net->arcs[idx].head = &net->nodes[0];
        net->arcs[idx].nextin = NULL;
        net->arcs[idx].nextout = NULL;
    }

    // Ensure memory is touched to prevent lazy allocation issues
    for (long j = 1; j <= net->n_trips; j++) {
        long idx = 3 * j - 1;
        if (idx > net->m) break;
        net->arcs[idx].cost = 0;
        net->arcs[idx].org_cost = 0;
    }
}