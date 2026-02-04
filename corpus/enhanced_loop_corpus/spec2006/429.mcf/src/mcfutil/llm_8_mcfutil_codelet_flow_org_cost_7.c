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
    arc_t *current_arc = net->arcs;
    long local_fleet = 0;
    cost_t local_cost = 0;
    long count = 0;
    const long batch_size = 4;
    arc_t *arc_end = (arc_t *)stop;

    for (; current_arc + batch_size <= arc_end; current_arc += batch_size) {
        for (int i = 0; i < batch_size; i++) {
            arc_t *a = &current_arc[i];
            if (a->flow) {
                if (!(a->tail->number < 0 && a->head->number > 0)) {
                    if (!a->tail->number) {
                        local_cost += (a->org_cost - net->bigM);
                        local_fleet++;
                    } else {
                        local_cost += a->org_cost;
                    }
                }
            }
        }
        count += batch_size;
    }

    for (; current_arc != arc_end; current_arc++) {
        if (current_arc->flow) {
            if (!(current_arc->tail->number < 0 && current_arc->head->number > 0)) {
                if (!current_arc->tail->number) {
                    local_cost += (current_arc->org_cost - net->bigM);
                    local_fleet++;
                } else {
                    local_cost += current_arc->org_cost;
                }
            }
        }
    }

    operational_cost += local_cost;
    fleet += local_fleet;
}
