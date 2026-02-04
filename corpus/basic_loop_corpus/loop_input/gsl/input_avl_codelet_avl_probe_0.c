#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct gsl_bst_avl_node {
    struct gsl_bst_avl_node *avl_link[2];
    void *avl_data;
    signed char avl_balance;
};

typedef struct gsl_bst_avl_node avl_node;

avl_node *y;
avl_node *p;
avl_node *n;
unsigned char da[32];
int k;

#define NODE_COUNT 100000

static avl_node nodes[NODE_COUNT];

void init_vars() {
    // Initialize the array of nodes to form a balanced AVL tree structure
    for (int i = 0; i < NODE_COUNT; i++) {
        nodes[i].avl_data = NULL;
        nodes[i].avl_balance = 0;
        // Left child
        if (2 * i + 1 < NODE_COUNT)
            nodes[i].avl_link[0] = &nodes[2 * i + 1];
        else
            nodes[i].avl_link[0] = &nodes[NODE_COUNT - 1]; // leaf points to sentinel
        // Right child
        if (2 * i + 2 < NODE_COUNT)
            nodes[i].avl_link[1] = &nodes[2 * i + 2];
        else
            nodes[i].avl_link[1] = &nodes[NODE_COUNT - 1]; // leaf points to sentinel
    }

    // Set sentinel node to last node
    n = &nodes[NODE_COUNT - 1];

    // Start traversal from root
    y = &nodes[0];

    // Initialize direction array with alternating pattern
    for (int i = 0; i < 32; i++) {
        da[i] = (i % 3 == 0) ? 1 : 0;  // Mostly go left, occasionally right
    }

    // Initialize loop counter
    k = 0;

    // Ensure p is initialized by assignment in loop setup
}