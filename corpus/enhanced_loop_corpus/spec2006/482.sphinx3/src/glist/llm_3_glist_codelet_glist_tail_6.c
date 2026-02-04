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
    // Variant 2: Strided memory access pattern
    // Instead of visiting every node, we skip nodes in a fixed stride (stride = 2), then finalize with direct traversal
    // This simulates prefetching or block-based processing patterns.
    gnode_t *current = g;
    gnode_t *next_check;

    // Strided forward jump: advance by two nodes at a time if possible
    for (; current && (next_check = current->next ? current->next->next : NULL); current = next_check) {
        // Empty body – just advancing with stride 2
    }

    // Final pass: ensure we reach the actual last node (in case of odd-length list)
    if (current && current->next) {
        for (; current->next; current = current->next)
            ;
    }
    gn = current;
}
