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

typedef struct basket {
    arc_t *a;
    cost_t cost;
    cost_t abs_cost;
} BASKET;

BASKET basket[351];
BASKET *perm[351];
long i;

void init_vars() {
    for (int idx = 0; idx < 351; idx++) {
        basket[idx].a = NULL;
        basket[idx].cost = (cost_t)(idx * 7);
        basket[idx].abs_cost = (cost_t)(idx * 11);
        perm[idx] = NULL;
    }
}

void loop(); 

void wrapper() {
    init_vars();
    loop();
}