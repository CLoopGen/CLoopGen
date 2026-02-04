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



void loop(){
    int32 local_ascr = 0;
    int32 local_lscr = 0;
    int32 count = 0;
    gnode_t *temp = hyp;
    while (temp != NULL) {
        hyp_t *h_local = (hyp_t *)(temp->data.ptr);
        local_ascr += h_local->ascr;
        local_lscr += h_local->lscr;
        temp = temp->next;
        count++;
    }
    // Unroll by processing two nodes per iteration if possible
    for (gn = hyp; gn && gn->next; gn = gn->next->next) {
        hyp_t *h1 = (hyp_t *)((gn)->data.ptr);
        hyp_t *h2 = (hyp_t *)((gn->next)->data.ptr);
        ascr += h1->ascr + h2->ascr;
        lscr += h1->lscr + h2->lscr;
    }
    // Handle remaining node if count is odd
    if (gn) {
        h = (hyp_t *)((gn)->data.ptr);
        ascr += h->ascr;
        lscr += h->lscr;
    }
}
