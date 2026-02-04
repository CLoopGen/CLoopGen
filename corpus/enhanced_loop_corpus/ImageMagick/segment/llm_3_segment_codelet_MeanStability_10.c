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

extern IntervalTree *child;
extern ssize_t count;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access through an array of pointers built on-the-fly to simulate indirect indexing
    // Simulates a scatter/gather pattern where nodes are accessed non-sequentially
    // We create a local array to collect pointers first (bounded by a reasonable limit to avoid overflow)
    #define MAX_NODES 1024
    IntervalTree *node_array[MAX_NODES];
    int num_nodes = 0;
    IntervalTree *temp = child;
    
    // Traverse and collect nodes
    for (; temp != (IntervalTree *)((void *)0) && num_nodes < MAX_NODES; temp = temp->sibling) {
        node_array[num_nodes++] = temp;
    }
    
    // Now perform indirect access: reverse order (last to first) to demonstrate non-consecutive access
    for (int i = num_nodes - 1; i >= 0; i--) {
        sum += node_array[i]->stability;
        count++;
    }
}
