#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

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

typedef struct basket {
    arc_t *a;
    cost_t cost;
    cost_t abs_cost;
} BASKET;

long basket_size = 50;
BASKET *perm[351];
long i;
long next;
arc_t *arc;
cost_t red_cost;

static node_p nodes_pool;
static arc_t *arcs_pool;
static BASKET baskets_pool[351];

void init_vars() {
    const long num_nodes = 100;
    const long num_arcs = 350;

    nodes_pool = (node_p)calloc(num_nodes, sizeof(struct node));
    arcs_pool = (arc_t *)calloc(num_arcs, sizeof(struct arc));

    for (long j = 0; j < num_nodes; j++) {
        nodes_pool[j].potential = (cost_t)(j * 10 - 500);
        nodes_pool[j].orientation = j % 2;
        nodes_pool[j].child = NULL;
        nodes_pool[j].pred = NULL;
        nodes_pool[j].sibling = NULL;
        nodes_pool[j].sibling_prev = NULL;
        nodes_pool[j].basic_arc = NULL;
        nodes_pool[j].firstout = NULL;
        nodes_pool[j].firstin = NULL;
        nodes_pool[j].arc_tmp = NULL;
        nodes_pool[j].flow = (flow_t)j * 100;
        nodes_pool[j].depth = j;
        nodes_pool[j].number = j;
        nodes_pool[j].time = j + 1000;
    }

    for (long j = 0; j < num_arcs; j++) {
        arcs_pool[j].cost = (cost_t)(j * 5 - 1000);
        arcs_pool[j].tail = &nodes_pool[j % num_nodes];
        arcs_pool[j].head = &nodes_pool[(j + 1) % num_nodes];
        arcs_pool[j].ident = (j % 3 == 0) ? 1 : ((j % 3 == 1) ? 2 : 0);
        arcs_pool[j].nextout = NULL;
        arcs_pool[j].nextin = NULL;
        arcs_pool[j].flow = (flow_t)(j * 200);
        arcs_pool[j].org_cost = arcs_pool[j].cost;
    }

    for (int j = 0; j < 351; j++) {
        if (j >= 2 && j <= basket_size) {
            baskets_pool[j].a = &arcs_pool[j - 2];
            baskets_pool[j].cost = 0;
            baskets_pool[j].abs_cost = 0;
            perm[j] = &baskets_pool[j];
        } else {
            baskets_pool[j].a = NULL;
            baskets_pool[j].cost = 0;
            baskets_pool[j].abs_cost = 0;
            perm[j] = &baskets_pool[j];
        }
    }

    i = 0;
    next = 0;
    arc = NULL;
    red_cost = 0;
}