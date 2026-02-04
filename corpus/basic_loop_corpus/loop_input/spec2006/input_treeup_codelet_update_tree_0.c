#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

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

long cycle_ori = 1;
flow_t delta = 100;
node_t *jminus = NULL;
node_t *w = NULL;
node_t *temp = NULL;
long depth_iminus = 5;

#define NODE_COUNT 2000000

static node_t nodes[NODE_COUNT];

void init_vars() {
    for (int i = 0; i < NODE_COUNT; i++) {
        nodes[i].orientation = (i % 2) ? 1 : 0;
        nodes[i].flow = i * 10;
        nodes[i].depth = i * 2;
        nodes[i].number = i;
        nodes[i].time = i + 100;
        nodes[i].potential = i * 5;
        nodes[i].child = NULL;
        nodes[i].sibling = NULL;
        nodes[i].sibling_prev = NULL;
        nodes[i].basic_arc = NULL;
        nodes[i].firstout = NULL;
        nodes[i].firstin = NULL;
        nodes[i].arc_tmp = NULL;
        nodes[i].pred = (i == 0) ? NULL : &nodes[i - 1];
    }

    jminus = &nodes[NODE_COUNT - 1];
    w = &nodes[0];
}