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
extern long fleet;
extern cost_t operational_cost;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential traversal, access arcs with a stride of 2 (unroll-like pattern)
    // This changes the memory access pattern to non-consecutive but predictable strides.
    arc_t* current = net->arcs;
    long stride = 2;
    long total_arcs = net->m_impl; // Assumed available field for number of implemented arcs

    for (long i = 0; i < total_arcs; i += stride) {
        arc = &current[i];
        if (arc->flow) {
            if (!(arc->tail->number < 0 && arc->head->number > 0)) {
                if (!arc->tail->number) {
                    operational_cost += (arc->cost - net->bigM);
                    fleet++;
                } else
                    operational_cost += arc->cost;
            }
        }

        // Second operation in the same iteration (simulating unrolled body)
        long j = i + 1;
        if (j < total_arcs) {
            arc = &current[j];
            if (arc->flow) {
                if (!(arc->tail->number < 0 && arc->head->number > 0)) {
                    if (!arc->tail->number) {
                        operational_cost += (arc->cost - net->bigM);
                        fleet++;
                    } else
                        operational_cost += arc->cost;
                }
            }
        }
    }
}
