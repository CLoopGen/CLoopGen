#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef struct _SkipNode {
    size_t next[9];
    size_t count;
    size_t signature;
} SkipNode;

typedef struct _SkipList {
    ssize_t level;
    SkipNode *nodes;
} SkipList;

size_t color;
SkipList *p;
ssize_t level;
size_t search;
size_t update[9];

static SkipNode *nodes_buffer;
static SkipList list_instance;

void init_vars() {
    const size_t DATA_SIZE = 1 << 20; // ~1MB of skip nodes
    const size_t NUM_NODES = DATA_SIZE / sizeof(SkipNode);
    
    // Allocate buffer for nodes
    nodes_buffer = aligned_alloc(64, NUM_NODES * sizeof(SkipNode));
    if (!nodes_buffer) exit(1);
    
    // Initialize all nodes
    for (size_t i = 0; i < NUM_NODES; i++) {
        SkipNode *node = &nodes_buffer[i];
        node->count = 0;
        node->signature = i ^ 0xDEADBEEF;
        
        // Initialize next pointers to form valid chain within bounds
        for (int j = 0; j < 9; j++) {
            // Create forward links with increasing stride per level
            size_t target = i + (1ULL << j);
            node->next[j] = (target < NUM_NODES) ? target : NUM_NODES - 1;
        }
    }
    
    // Set up the skiplist instance
    p = &list_instance;
    p->level = 8;  // Must match the array size in SkipNode.next and loop bound
    p->nodes = nodes_buffer;
    
    // Initialize global variables for loop entry
    color = NUM_NODES - 100;  // Target near end to ensure traversal depth
    search = 0;               // Start from head node
    
    // Clear update array
    for (int i = 0; i < 9; i++) {
        update[i] = 0;
    }
}