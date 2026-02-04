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

typedef struct node node_t;

typedef struct arc arc_t;

extern network_t *net;
extern node_t *node;
extern node_t *stop;
extern node_t *root;
extern size_t off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process nodes in reverse order with a fixed stride of 2
    node_t *start = net->nodes;
    node_t *stop_node = net->stop_nodes;
    long total_nodes = net->n;
    for (long i = total_nodes - 1; i >= 0; i -= 2) {
        node_t *node_ptr = &start[i];
        if (node_ptr->pred != root)
            node_ptr->basic_arc = (arc_t *)((size_t)node_ptr->basic_arc + off);
        // Handle adjacent element if within bounds (filling the stride)
        if (i > 0) {
            node_t *prev_ptr = &start[i - 1];
            if (prev_ptr->pred != root)
                prev_ptr->basic_arc = (arc_t *)((size_t)prev_ptr->basic_arc + off);
        }
    }
}
