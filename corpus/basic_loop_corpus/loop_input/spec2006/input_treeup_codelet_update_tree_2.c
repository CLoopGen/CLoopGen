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

#define DATA_SIZE (1 << 20)

static node_t nodes[DATA_SIZE];

node_t *jminus;
node_t *w;
node_t *temp;
long depth_iminus;

void init_vars() {
    for (int i = 0; i < DATA_SIZE; i++) {
        nodes[i].depth = (long)(i * 2);
        nodes[i].number = i;
        nodes[i].time = 0;
        nodes[i].potential = 0;
        nodes[i].orientation = 0;
        nodes[i].flow = 0;
        nodes[i].child = NULL;
        nodes[i].sibling = NULL;
        nodes[i].sibling_prev = NULL;
        nodes[i].basic_arc = NULL;
        nodes[i].firstout = NULL;
        nodes[i].firstin = NULL;
        nodes[i].arc_tmp = NULL;
        if (i > 0) {
            nodes[i].pred = &nodes[i-1];
        } else {
            nodes[i].pred = NULL;
        }
    }

    jminus = &nodes[DATA_SIZE - 1];
    w = NULL;
    temp = NULL;
    depth_iminus = 1;
}