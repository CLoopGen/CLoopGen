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

typedef struct arc arc_t;

extern network_t *net;
extern arc_t *arc;
extern void *stop;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2 (forward skipping)
    arc_t *arc_ptr = net->arcs;
    arc_t *stop_arc = (arc_t *)stop;

    for (; arc_ptr < stop_arc; arc_ptr += 2) {
        // Handle current element
        if (arc_ptr->ident == 2)
            arc_ptr->flow = (flow_t)1;
        else
            arc_ptr->flow = (flow_t)0;

        // Handle next consecutive element if within bounds
        arc_t *next_arc = arc_ptr + 1;
        if (next_arc < stop_arc) {
            if (next_arc->ident == 2)
                next_arc->flow = (flow_t)1;
            else
                next_arc->flow = (flow_t)0;
        }
    }

    // Handle any potential odd-sized range by checking if last accessed is below stop
    if ((arc_t*)arc_ptr > stop_arc && (arc_ptr - 1) == stop_arc - 1) {
        // Ensure all elements are covered (redundant check, but safe)
        arc = stop_arc - 1;
        if (arc->ident == 2)
            arc->flow = (flow_t)1;
        else
            arc->flow = (flow_t)0;
    }

    // Final sweep from net->arcs to ensure no gaps (defensive, in case of misalignment)
    for (arc = net->arcs; arc != (arc_t *)stop; arc++) {
        if (arc->ident == 2)
            arc->flow = (flow_t)1;
        else
            arc->flow = (flow_t)0;
    }
}
