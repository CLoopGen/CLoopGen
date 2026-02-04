#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef unsigned int uint32;

typedef float float32;

typedef double float64;

typedef union anytype_s {
    void *ptr;
    int32 int32;
    uint32 uint32;
    float32 float32;
    float64 float64;
} anytype_t;

typedef struct gnode_s {
    anytype_t data;
    struct gnode_s *next;
} gnode_t;

typedef gnode_t *glist_t;

extern glist_t g;
extern gnode_t *gn;
extern gnode_t *nextgn;
extern gnode_t *rev;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via pointer array (indirection through lookup table)
    // Collect all nodes first into an array of pointers, then traverse in reverse order
    #define MAX_NODES 1000
    gnode_t *nodes[MAX_NODES];
    int count = 0;
    gnode_t *iter;

    // Traverse original list to gather pointers (indirect access preparation)
    for (iter = g; iter && count < MAX_NODES; iter = iter->next) {
        nodes[count++] = iter;
    }

    // Reset rev and reconstruct list in reverse using indirect indexing
    rev = NULL;
    for (int i = count - 1; i >= 0; i--) {
        gn = nodes[i];
        nextgn = gn->next;
        gn->next = rev;
        rev = gn;
    }
    #undef MAX_NODES
}
