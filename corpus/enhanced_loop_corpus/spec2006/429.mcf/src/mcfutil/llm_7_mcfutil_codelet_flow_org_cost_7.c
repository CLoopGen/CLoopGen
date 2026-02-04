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
    arc_t *temp_arc = net->arcs;
    cost_t temp_cost = operational_cost;
    long temp_fleet = fleet;

    for (long i = 0; &temp_arc[i] != (arc_t *)stop; i++) {
        arc_t *arc_ptr = &temp_arc[i];
        cost_t add_cost = 0;
        long fleet_incr = 0;

        if (arc_ptr->flow) {
            if (!(arc_ptr->tail->number < 0 && arc_ptr->head->number > 0)) {
                if (!arc_ptr->tail->number) {
                    add_cost = (arc_ptr->org_cost - net->bigM);
                    fleet_incr = 1;
                } else {
                    add_cost = arc_ptr->org_cost;
                }
            }
        }

        temp_cost += add_cost;
        temp_fleet += fleet_incr;
    }

    operational_cost = temp_cost;
    fleet = temp_fleet;
}
