#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef struct _IntervalTree {
    double tau;
    ssize_t left;
    ssize_t right;
    double mean_stability;
    double stability;
    struct _IntervalTree *sibling;
    struct _IntervalTree *child;
} IntervalTree;

double average_tau = 0.0;
IntervalTree **list = NULL;
ssize_t i = 0;
ssize_t number_nodes = 0;

void init_vars() {
    // Estimate data size to run loop for ~0.01 seconds
    // On modern CPUs, simple loops like this can process millions of iterations per ms
    // We'll target around 10 million nodes to ensure measurable time without being excessive
    
    number_nodes = 10000000; // 10 million nodes
    
    // Allocate array of pointers
    list = (IntervalTree**)calloc(number_nodes, sizeof(IntervalTree*));
    if (!list) {
        number_nodes = 0;
        return;
    }
    
    // Allocate and initialize each IntervalTree node
    for (ssize_t idx = 0; idx < number_nodes; idx++) {
        IntervalTree* node = (IntervalTree*)malloc(sizeof(IntervalTree));
        if (!node) continue;
        
        // Initialize with plausible values
        node->tau = (double)(idx % 1000) / 100.0; // Varying tau values between 0-9.99
        node->left = idx - 1;     // Example structural values
        node->right = idx + 1;
        node->mean_stability = 1.0;
        node->stability = 1.0;
        node->sibling = NULL;
        node->child = NULL;
        
        list[idx] = node;
    }
    
    // Fix boundary conditions
    if (number_nodes > 0 && list[0]) {
        list[0]->left = -1;
    }
    if (number_nodes > 0 && list[number_nodes-1]) {
        list[number_nodes-1]->right = -1;
    }
    
    // Reset average_tau since it's accumulated in the loop
    average_tau = 0.0;
}