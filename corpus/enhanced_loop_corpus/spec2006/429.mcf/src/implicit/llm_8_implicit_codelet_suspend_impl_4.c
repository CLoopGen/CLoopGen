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
for (susp = 0, arc = new_arc; arc < (arc_t *)stop; arc++) {
    red_cost = (arc->ident == 1) ? 
        (arc->cost - arc->tail->potential + arc->head->potential) : 
        ((arc->ident == 0) ? 
            (arc->tail->basic_arc == arc ? 
                (arc->tail->basic_arc = new_arc, (cost_t)-2) : 
                (arc->head->basic_arc = new_arc, (cost_t)-2)) : 
            (cost_t)-2);
    susp += (red_cost > threshold);
    if (red_cost <= threshold) {
        *new_arc = *arc;
        new_arc++;
    }
}
}
