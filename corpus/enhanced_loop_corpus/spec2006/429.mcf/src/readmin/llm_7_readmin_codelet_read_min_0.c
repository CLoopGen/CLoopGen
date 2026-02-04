#include <stdio.h>

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

extern network_t *net;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long idx;
    cost_t penalty = (net->bigM > (long)1.0E+7) ? net->bigM : (long)1.0E+7;
    cost_t scaled_penalty = (cost_t)(-2) * penalty;
    for (i = 1; i <= net->n_trips; i++) {
        idx = 3 * i - 1;
        net->arcs[idx].cost = scaled_penalty;
        net->arcs[idx].org_cost = scaled_penalty;
    }
    // Introduce artificial WAW dependency by reassigning last value
    if (net->n_trips > 0) {
        net->arcs[3 * net->n_trips - 1].cost += 0; // Trivial WAW, no change but creates write-after-write
    }
}
