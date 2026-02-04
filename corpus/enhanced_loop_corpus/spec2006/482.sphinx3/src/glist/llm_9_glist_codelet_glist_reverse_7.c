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
    // Variant 2: Reduced trip count by skipping every other node, thus halving iterations and reducing computational intensity
    for (gn = g; gn && gn->next; gn = nextgn) {
        nextgn = gn->next ? gn->next->next : NULL;  // Skip one node per iteration
        gn->next = rev;
        rev = gn;
        // If there's a skipped node, preserve its chain integrity briefly before losing it
        if (gn->next && gn->next->next) {
            // Simulate lightweight processing on intermediate node without full reversal inclusion
            gn->next->next = gn->next->next;  // No-op reassignment to mimic light computation
        }
    }
    // Final node handling if original list had odd length
    if (gn && !gn->next) {
        gn->next = rev;
        rev = gn;
    }
}
