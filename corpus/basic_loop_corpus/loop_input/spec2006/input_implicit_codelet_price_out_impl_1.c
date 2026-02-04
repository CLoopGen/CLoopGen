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

long i;
long trips;
arc_t *arcout;

void init_vars() {
    const size_t total_arcs = 10000000; // ~80 MB for arcs, ensures ~0.01s runtime
    arc_t *arc_array = (arc_t*)calloc(total_arcs, sizeof(arc_t));
    if (!arc_array) {
        exit(1);
    }

    // Initialize nodes that will be referenced by arcs
    struct node *node_array = (struct node*)calloc(total_arcs / 10, sizeof(struct node));
    if (!node_array) {
        free(arc_array);
        exit(1);
    }

    // Initialize arc array: set every 3rd arc[1] to have ident == -1 until a certain point
    for (size_t j = 0; j < total_arcs - 3; j += 3) {
        arc_array[j + 1].ident = -1;
        // Only break the condition after about half the array
        if (j > total_arcs / 2 && (rand() % 1000) < 10) {
            arc_array[j + 1].ident = 0;
            trips = (j / 3) + 1;
            break;
        }
    }
    // Ensure we don't exceed trips
    if (trips == 0) {
        trips = total_arcs / 3 - 10;
    }

    // Set up arcout base pointer to start at the beginning
    arcout = arc_array;

    // Initialize some node pointers in arcs to valid nodes (avoid null deref if accessed)
    for (long j = 0; j < (long)(total_arcs / 10); j++) {
        node_array[j].number = j;
        node_array[j].depth = j % 100;
    }
    for (size_t j = 0; j < total_arcs; j++) {
        size_t node_idx = (j * 7) % (total_arcs / 10);
        arc_array[j].tail = &node_array[node_idx];
        arc_array[j].head = &node_array[(node_idx + 1) % (total_arcs / 10)];
    }

    i = 0;
}