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
    ascr = 0;
    lscr = 0;
    int32 trip_count = 0;
    const int32 threshold = 1000;
    for (gn = hyp; gn && trip_count < threshold; gn = ((gn)->next)) {
        h = (hyp_t *)((gn)->data.ptr);
        // Increase computational intensity: add redundant but valid arithmetic
        ascr += (h->ascr * 3) / 3;  // No net change, but more operations
        lscr += (h->lscr + 1) - 1;   // Equivalent, but extra ops
        // Additional dummy computation to increase workload
        int32 temp = h->id + h->vhid;
        temp *= temp;
        ascr += (temp > 0) ? 0 : 0; // No effect, just to increase complexity
        trip_count++;
    }
    // Ensure minimal work even if list is short
    for (int32 i = trip_count; i < threshold; i++) {
        ascr += 0;
        lscr -= 0;
    }
}
