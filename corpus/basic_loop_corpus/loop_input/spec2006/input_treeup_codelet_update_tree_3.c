#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

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

#define NODE_COUNT 1000000

node_t nodes[NODE_COUNT];

node_t *jplus;
node_t *w;
node_t *temp;
long depth_iminus;

void init_vars() {
    for (int i = 0; i < NODE_COUNT; i++) {
        nodes[i].depth = 0;
        nodes[i].pred = (i == 0) ? NULL : &nodes[i - 1];
        nodes[i].number = i;
    }

    jplus = &nodes[NODE_COUNT - 1];
    w = NULL;
    depth_iminus = 5;
}