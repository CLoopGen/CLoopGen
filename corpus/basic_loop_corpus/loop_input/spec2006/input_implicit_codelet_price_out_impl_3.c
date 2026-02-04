#include <stdio.h>
#include <stdlib.h>
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

#define DATA_SIZE_MB 64
#define NUM_ARCS (DATA_SIZE_MB * (1 << 20) / sizeof(arc_t))

static arc_t *arc_array = NULL;
arc_t *arcnew;
arc_t *stop;

static struct node *node_pool = NULL;
static size_t num_nodes = 0;

void init_vars() {
    size_t i;

    num_nodes = NUM_ARCS / 8 + 2;
    if (num_nodes < 2) num_nodes = 2;

    node_pool = (struct node *)calloc(num_nodes, sizeof(struct node));
    if (!node_pool) exit(1);

    for (i = 0; i < num_nodes; i++) {
        node_pool[i].number = (int)i;
        node_pool[i].time = 0;
        node_pool[i].depth = 0;
        node_pool[i].flow = 0;
        node_pool[i].potential = 0;
        node_pool[i].orientation = 0;
        node_pool[i].child = NULL;
        node_pool[i].pred = NULL;
        node_pool[i].sibling = NULL;
        node_pool[i].sibling_prev = NULL;
        node_pool[i].basic_arc = NULL;
        node_pool[i].firstout = NULL;
        node_pool[i].firstin = NULL;
        node_pool[i].arc_tmp = NULL;
    }

    arc_array = (arc_t *)calloc(NUM_ARCS, sizeof(arc_t));
    if (!arc_array) exit(1);

    for (i = 0; i < NUM_ARCS; i++) {
        arc_array[i].cost = (cost_t)(i * 7);
        arc_array[i].org_cost = arc_array[i].cost;
        arc_array[i].flow = 0;
        arc_array[i].ident = 0;
        arc_array[i].nextout = NULL;
        arc_array[i].nextin = NULL;
        arc_array[i].tail = &node_pool[i % num_nodes];
        arc_array[i].head = &node_pool[(i + 1) % num_nodes];
    }

    arcnew = arc_array;
    stop = arc_array + NUM_ARCS;
}