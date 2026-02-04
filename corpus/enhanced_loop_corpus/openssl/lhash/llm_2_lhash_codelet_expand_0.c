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
    // Variant 1: Consecutive memory access pattern using array-like traversal
    // Assuming OPENSSL_LH_NODE** n1 and n2 are treated as pointers to arrays of node pointers
    // We simulate consecutive access by temporarily storing nodes in a local array for batch processing

    #define MAX_NODES 1024
    OPENSSL_LH_NODE *temp_nodes[MAX_NODES];
    int count = 0;

    // First pass: collect all nodes from the chain into a local array (consecutive access)
    for (np = *n1; np != ((void *)0) && count < MAX_NODES;) {
        temp_nodes[count++] = np;
        np = np->next;
    }

    // Second pass: reprocess collected nodes with consecutive array indexing
    for (int i = 0; i < count; ++i) {
        np = temp_nodes[i];
        hash = np->hash;
        if ((hash % nni) != p) {
            np->next = *n2;
            *n2 = np;
        }
    }

    // Reconstruct *n1: after moving mismatched nodes, only matched ones remain
    *n1 = ((void *)0);
    for (int i = 0; i < count; ++i) {
        np = temp_nodes[i];
        hash = np->hash;
        if ((hash % nni) == p) {
            if (*n1 == ((void *)0)) {
                static OPENSSL_LH_NODE sentinel;
                sentinel.next = np;
                *n1 = &sentinel;
                break;
            }
        }
    }
    if (*n1 != ((void *)0)) *n1 = (*n1)->next;
}
