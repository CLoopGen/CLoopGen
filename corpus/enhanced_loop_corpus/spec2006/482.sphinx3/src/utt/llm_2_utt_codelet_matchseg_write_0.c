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

typedef struct {
    int32 id;
    int32 vhid;
    int32 sf;
    int32 ef;
    int32 ascr;
    int32 lscr;
    int32 type;
} hyp_t;

extern glist_t hyp;
extern gnode_t *gn;
extern hyp_t *h;
extern int32 ascr;
extern int32 lscr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of traversing every node in sequence, access every second node (stride of 2)
    // This creates a strided memory access pattern, potentially improving cache behavior 
    // in certain scenarios or modeling sparse traversal.

    gnode_t *current;
    for (gn = hyp; gn && gn->next; gn = ((gn)->next ? (gn)->next->next : NULL)) {
        h = (hyp_t *)((gn)->data.ptr);
        ascr += h->ascr;
        lscr += h->lscr;

        // Process next valid node if available within stride
        current = gn->next;
        if (current) {
            h = (hyp_t *)(current->data.ptr);
            ascr += h->ascr;
            lscr += h->lscr;
        }
    }
}
