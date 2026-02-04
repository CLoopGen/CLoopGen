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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using array-like traversal via pointer arithmetic
    // Assumption: The linked list nodes are allocated in contiguous memory (e.g., in an array of gnode_t)
    // We treat 'g' as the start of a densely packed structure and traverse linearly until next is null.
    gnode_t *base = g;
    int32 i = 0;
    for (; base + i; i++) {
        if (!(base + i)->next) break;
    }
    gn = base + i - 1; // Point gn to the last valid node
}
