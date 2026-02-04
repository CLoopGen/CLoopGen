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
    long index;
    for (susp = 0, arc = new_arc, index = 0; arc < (arc_t *)stop; arc++, index++) {
        if ((index % 2) == 0 && arc->ident == 1)
            red_cost = arc->cost - arc->tail->potential + arc->head->potential;
        else {
            red_cost = (cost_t)-2;
            if (arc->ident == 0) {
                if (arc->tail->basic_arc == arc)
                    arc->tail->basic_arc = new_arc;
                else
                    arc->head->basic_arc = new_arc;
            }
        }
        if (red_cost > threshold)
            susp++;
        else {
            *new_arc = *arc;
            new_arc++;
        }
    }
}
