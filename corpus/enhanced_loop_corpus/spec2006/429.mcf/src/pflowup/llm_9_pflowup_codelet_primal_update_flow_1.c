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


typedef struct node node_t;

extern node_t *jplus;
extern node_t *w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t count = 0;
    node_t *temp = jplus;
    while (temp != w) {
        count++;
        temp = temp->pred;
    }
    jplus->flow = (flow_t)(jplus->orientation ? 1 : 0);
    for (size_t i = 1; i < count; i++) {
        jplus = jplus->pred;
        jplus->flow = (flow_t)(i % 2 == 0 ? (jplus->orientation ? 1 : 0) : !jplus->orientation);
    }
}
