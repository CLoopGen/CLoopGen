#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _IntervalTree {
    double tau;
    ssize_t left;
    ssize_t right;
    double mean_stability;
    double stability;
    struct _IntervalTree *sibling;
    struct _IntervalTree *child;
} IntervalTree;

IntervalTree *child = (IntervalTree *)((void *)0);
ssize_t count = 0;
double sum = 0.0;

#define NUM_NODES 1000000

static IntervalTree node_pool[NUM_NODES];
static int initialized = 0;

void init_vars() {
    if (initialized) return;
    
    for (int i = 0; i < NUM_NODES; i++) {
        node_pool[i].tau = (double)(i + 1) * 0.1;
        node_pool[i].left = -1;
        node_pool[i].right = -1;
        node_pool[i].mean_stability = (double)(i % 100) * 0.5;
        node_pool[i].stability = (double)(i % 200) * 0.25;
        node_pool[i].sibling = (i == NUM_NODES - 1) ? (IntervalTree *)((void *)0) : &node_pool[i + 1];
        node_pool[i].child = (IntervalTree *)((void *)0);
    }

    child = &node_pool[0];
    count = 0;
    sum = 0.0;
    initialized = 1;
}