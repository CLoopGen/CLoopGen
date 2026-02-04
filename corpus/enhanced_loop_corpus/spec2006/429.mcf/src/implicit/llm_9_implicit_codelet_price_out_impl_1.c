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

extern long i;
extern long trips;
extern arc_t *arcout;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < trips * 2 && arcout[1].ident == -1; i++, arcout += 2) {
        cost_t temp_cost = arcout->cost;
        temp_cost -= arcout->org_cost;
        arcout->flow += (flow_t)(temp_cost > 0 ? 1 : -1);
        arcout->head->potential += temp_cost / 2;
        arcout->tail->potential -= temp_cost / 2;
    }
}
