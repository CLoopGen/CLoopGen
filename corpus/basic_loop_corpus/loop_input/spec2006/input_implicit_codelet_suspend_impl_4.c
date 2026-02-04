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

cost_t threshold;
long susp;
cost_t red_cost;
arc_t *new_arc;
arc_t *arc;
void *stop;

#define DATA_SIZE (1 << 20)  // ~8MB of arcs, adjust for ~0.01s runtime

static arc_t *arc_array;
static struct node *node_pool;

void init_vars() {
    threshold = 100;
    red_cost = 0;
    susp = 0;

    // Allocate memory pools
    arc_array = calloc(DATA_SIZE, sizeof(arc_t));
    node_pool = calloc(DATA_SIZE * 2, sizeof(struct node));  // More nodes than arcs

    if (!arc_array || !node_pool) {
        exit(1);
    }

    // Initialize nodes and arcs
    for (long i = 0; i < DATA_SIZE * 2; i++) {
        node_pool[i].potential = i % 50;
        node_pool[i].basic_arc = NULL;
        node_pool[i].flow = 0;
        node_pool[i].depth = i % 10;
        node_pool[i].number = i;
        node_pool[i].time = 0;
    }

    for (long i = 0; i < DATA_SIZE; i++) {
        arc_array[i].cost = (i % 200) - 100;
        arc_array[i].org_cost = arc_array[i].cost;
        arc_array[i].tail = &node_pool[i];
        arc_array[i].head = &node_pool[DATA_SIZE + (i % DATA_SIZE)];
        arc_array[i].ident = (i % 3 == 0) ? 1 : ((i % 3 == 1) ? 0 : 2);
        arc_array[i].flow = i % 1000;
        arc_array[i].nextout = NULL;
        arc_array[i].nextin = NULL;
    }

    new_arc = arc_array;
    arc = arc_array;
    stop = &arc_array[DATA_SIZE];
}