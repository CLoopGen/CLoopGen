#include <stdio.h>

#include <inttypes.h>

typedef long flow_t;

typedef long cost_t;

typedef struct node *node_p;

typedef struct arc *arc_p;

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


typedef struct node node_t;

extern long cycle_ori;
extern flow_t delta;
extern node_t *jminus;
extern node_t *w;
extern node_t *temp;
extern long depth_iminus;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (temp = jminus; temp != w; temp = temp->pred) {
    temp->depth -= depth_iminus;
    if (temp->orientation == cycle_ori) {
        temp->flow -= delta;
        continue;
    }
    temp->flow += delta;
}
}
