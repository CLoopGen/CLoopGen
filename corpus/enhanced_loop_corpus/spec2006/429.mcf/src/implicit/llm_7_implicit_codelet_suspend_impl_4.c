#include <stdio.h>

#include <inttypes.h>

typedef long cost_t;

typedef struct node *node_p;

typedef struct arc *arc_p;

typedef long flow_t;

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


typedef struct arc arc_t;

extern cost_t threshold;
extern long susp;
extern cost_t red_cost;
extern arc_t *new_arc;
extern arc_t *arc;
extern void *stop;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    arc_t *local_new_arc = new_arc;
    long local_susp = 0;
    cost_t local_threshold = threshold;

    for (arc = new_arc; arc < (arc_t *)stop; arc++) {
        cost_t computed_red_cost;

        if (arc->ident == 1) {
            computed_red_cost = arc->cost - arc->tail->potential + arc->head->potential;
        } else {
            computed_red_cost = (cost_t)-2;
            if (arc->ident == 0) {
                if (arc->tail->basic_arc == arc)
                    arc->tail->basic_arc = local_new_arc;
                else
                    arc->head->basic_arc = local_new_arc;
            }
        }

        if (computed_red_cost > local_threshold) {
            local_susp++;
        } else {
            *local_new_arc = *arc;
            local_new_arc++;
        }
    }

    // Update shared globals only once at the end to eliminate loop-carried WAW and WAR dependencies
    new_arc = local_new_arc;
    susp = local_susp;
}
