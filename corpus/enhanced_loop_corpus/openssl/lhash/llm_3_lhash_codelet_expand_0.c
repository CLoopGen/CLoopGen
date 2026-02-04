#include <stdio.h>

#include <inttypes.h>

struct lhash_node_st {
    void *data;
    struct lhash_node_st *next;
    unsigned long hash;
};


typedef struct lhash_node_st OPENSSL_LH_NODE;

extern OPENSSL_LH_NODE **n1;
extern OPENSSL_LH_NODE **n2;
extern OPENSSL_LH_NODE *np;
extern unsigned int p;
extern unsigned int nni;
extern unsigned long hash;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access pattern
    // Process every 'stride'-th node in a round-robin fashion to create non-sequential access
    const int stride = 3;  // Example stride value for scattering access
    OPENSSL_LH_NODE *nodes_buffer[stride];
    int valid[stride];
    int i;

    // Initialize buffer
    for (i = 0; i < stride; ++i) {
        nodes_buffer[i] = ((void *)0);
        valid[i] = 0;
    }

    // Prime the buffer with first 'stride' nodes from the list
    np = *n1;
    for (i = 0; i < stride && np != ((void *)0); ++i) {
        nodes_buffer[i] = np;
        valid[i] = 1;
        np = np->next;
    }

    // Use a counted loop instead of while to avoid while/do-while
    // Simulate strided traversal by jumping through stored nodes
    for (int round = 0; round < 1000 && np != ((void *)0); ++round) {
        for (i = 0; i < stride; ++i) {
            if (!valid[i]) continue;

            np = nodes_buffer[i];
            hash = np->hash;

            if ((hash % nni) != p) {
                // Remove from current position and move to n2
                *n1 = (*n1)->next;
                np->next = *n2;
                *n2 = np;
            } else {
                n1 = &(nodes_buffer[i]->next);
            }

            // Refill buffer slot from remaining list
            if (np->next != ((void *)0)) {
                nodes_buffer[i] = np->next;
                valid[i] = 1;
            } else {
                valid[i] = 0;
            }
        }
    }

    // Final cleanup: process any remaining buffered nodes
    for (i = 0; i < stride; ++i) {
        if (valid[i]) {
            np = nodes_buffer[i];
            hash = np->hash;
            if ((hash % nni) != p) {
                np->next = *n2;
                *n2 = np;
            }
        }
    }
}
