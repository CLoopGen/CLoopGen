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

long cycle_ori;
flow_t delta;
node_t *jplus;
node_t *w;
node_t *temp;
long depth_iminus;

#define NODE_COUNT 1000000

static node_t nodes[NODE_COUNT];

void init_vars() {
    cycle_ori = 1;
    delta = 100;
    depth_iminus = 5;

    for (int i = 0; i < NODE_COUNT; ++i) {
        nodes[i].orientation = (i % 2 == 0) ? 1 : 0;
        nodes[i].flow = i * 10;
        nodes[i].depth = i * 2;
        nodes[i].pred = (i == 0) ? NULL : &nodes[i - 1];
        nodes[i].number = i;
    }

    jplus = &nodes[NODE_COUNT - 1];
    w = NULL;
}