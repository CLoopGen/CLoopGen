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

void init_vars() {
    const size_t num_arcs = 5000000; // ~40 MB of arc data, sufficient for ~0.01 sec runtime
    net = (network_t*)calloc(1, sizeof(network_t));
    net->arcs = (arc_p)calloc(num_arcs, sizeof(struct arc));
    net->stop_arcs = net->arcs + num_arcs;

    for (size_t i = 0; i < num_arcs; i++) {
        net->arcs[i].ident = (i % 7 == 0) ? -1 : 0; // some -1, others not
        net->arcs[i].cost = i * 37;
        net->arcs[i].org_cost = i * 11;
        net->arcs[i].flow = i * 100;
        net->arcs[i].tail = NULL;
        net->arcs[i].head = NULL;
        net->arcs[i].nextin = NULL;
        net->arcs[i].nextout = NULL;
    }

    net->nodes = NULL;
    net->stop_nodes = NULL;
    net->dummy_arcs = NULL;
    net->stop_dummy = NULL;
    net->m = num_arcs;
    net->m_org = num_arcs;
    net->n = 1000;
    net->feasible = 1;
    net->eps = 1e-6;
    net->opt_tol = 1e-6;
    net->feas_tol = 1e-6;
    net->bigM = 1000000;
    net->optcost = 0.0;
    net->ignore_impl = 0;

    arc = net->arcs;
    stop = net->stop_arcs;
}