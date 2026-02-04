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

typedef struct arc arc_t;

network_t *net;
arc_t *arc;

void init_vars() {
    const size_t data_size = 134217728; // ~128MB to target ~0.01s runtime
    const long num_arcs = data_size / sizeof(arc_t);

    net = (network_t *)malloc(sizeof(network_t));
    memset(net, 0, sizeof(network_t));

    net->arcs = (arc_p)malloc(data_size);
    net->stop_arcs = net->arcs + num_arcs;

    arc = net->arcs;

    net->m = 0;
    net->n = 0;
    net->n_trips = 0;
    net->max_m = num_arcs;
    net->m_org = 0;
    net->m_impl = 0;
    net->max_residual_new_m = 0;
    net->max_new_m = 0;
    net->primal_unbounded = 0;
    net->dual_unbounded = 0;
    net->perturbed = 0;
    net->feasible = 0;
    net->eps = 0;
    net->opt_tol = 0;
    net->feas_tol = 0;
    net->pert_val = 0;
    net->bigM = 0;
    net->optcost = 0.0;
    net->ignore_impl = 0;
    net->iterations = 0;
    net->bound_exchanges = 0;
    net->checksum = 0;

    net->nodes = NULL;
    net->stop_nodes = NULL;
    net->dummy_arcs = NULL;
    net->stop_dummy = NULL;

    for (long i = 0; i < num_arcs; i++) {
        net->arcs[i].cost = i;
        net->arcs[i].org_cost = i;
        net->arcs[i].flow = 0;
        net->arcs[i].ident = i;
        net->arcs[i].tail = NULL;
        net->arcs[i].head = NULL;
        net->arcs[i].nextout = NULL;
        net->arcs[i].nextin = NULL;
    }
}