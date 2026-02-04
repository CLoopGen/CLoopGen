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
    int32 temp_ascr = 0;
    int32 temp_lscr = 0;
    gnode_t *iter = hyp;
    while (iter) {
        hyp_t *current_h = (hyp_t *)(iter->data.ptr);
        temp_ascr += current_h->ascr;
        temp_lscr += current_h->lscr;
        iter = iter->next;
    }
    ascr += temp_ascr;
    lscr += temp_lscr;
}
