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

extern node_t *iplus;
extern node_t *w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access – process every second node in reverse path to create stride-2 access pattern
    // This introduces non-unit stride in the traversal of the linked structure
    int step = 0;
    node_t* current = iplus;

    for (; current != w; ) {
        if (current->orientation)
            current->flow = (flow_t)0;
        else
            current->flow = (flow_t)1;

        // Traverse two steps in pred chain per iteration (strided access)
        if (current->pred != w && current->pred != NULL) {
            current = current->pred->pred;
        } else {
            break;
        }
        step++;
    }

    // Final pass: handle possible last node if path length is odd
    if (current != NULL && current == w && current->pred != NULL) {
        if (current->orientation)
            current->flow = (flow_t)0;
        else
            current->flow = (flow_t)1;
    }
}
