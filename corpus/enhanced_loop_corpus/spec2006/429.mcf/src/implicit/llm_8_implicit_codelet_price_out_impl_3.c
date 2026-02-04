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

extern arc_t *arcnew;
extern arc_t *stop;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; arcnew != stop; arcnew += 2) {
        if (arcnew + 1 >= stop) break;
        arcnew->flow = (flow_t)0;
        (arcnew+1)->flow = (flow_t)0;
        arcnew->ident = 1;
        (arcnew+1)->ident = 1;
        arcnew->nextout = arcnew->tail->firstout;
        (arcnew+1)->nextout = (arcnew+1)->tail->firstout;
        arcnew->tail->firstout = arcnew;
        (arcnew+1)->tail->firstout = arcnew+1;
        arcnew->nextin = arcnew->head->firstin;
        (arcnew+1)->nextin = (arcnew+1)->head->firstin;
        arcnew->head->firstin = arcnew;
        (arcnew+1)->head->firstin = arcnew+1;
    }
}
