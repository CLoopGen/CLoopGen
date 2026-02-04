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
    long total_arcs = net->m_impl;
    long stride = 4;
    arc_t *arc_base = (arc_t *)net->arcs;

    for (long i = 0; i < total_arcs; i += stride) {
        arc_t *arc1 = arc_base + i;
        if (i < total_arcs) {
            arc1->nextout = arc1->tail->firstout;
            arc1->tail->firstout = arc1;
            arc1->nextin = arc1->head->firstin;
            arc1->head->firstin = arc1;
        }
        if (i + 1 < total_arcs) {
            arc_t *arc2 = arc1 + 1;
            arc2->nextout = arc2->tail->firstout;
            arc2->tail->firstout = arc2;
            arc2->nextin = arc2->head->firstin;
            arc2->head->firstin = arc2;
        }
        if (i + 2 < total_arcs) {
            arc_t *arc3 = arc1 + 2;
            arc3->nextout = arc3->tail->firstout;
            arc3->tail->firstout = arc3;
            arc3->nextin = arc3->head->firstin;
            arc3->head->firstin = arc3;
        }
        if (i + 3 < total_arcs) {
            arc_t *arc4 = arc1 + 3;
            arc4->nextout = arc4->tail->firstout;
            arc4->tail->firstout = arc4;
            arc4->nextin = arc4->head->firstin;
            arc4->head->firstin = arc4;
        }
    }
}
