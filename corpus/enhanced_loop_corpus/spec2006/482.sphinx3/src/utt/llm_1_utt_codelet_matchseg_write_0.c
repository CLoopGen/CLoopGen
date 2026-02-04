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
    glist_t temp = hyp;
    for (; temp != NULL && temp->next != NULL; temp = temp->next->next) {
        h = (hyp_t *)(temp->data.ptr);
        ascr += h->ascr;
        lscr += h->lscr;
        
        if (temp->next != NULL) {
            h = (hyp_t *)(temp->next->data.ptr);
            ascr += h->ascr;
            lscr += h->lscr;
        }
    }
    if (temp != NULL) {
        h = (hyp_t *)(temp->data.ptr);
        ascr += h->ascr;
        lscr += h->lscr;
    }
}
