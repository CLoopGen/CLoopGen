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

typedef int32 s3wid_t;

typedef struct {
    s3wid_t wid;
    int32 fef;
    int32 lef;
    int32 seqid;
    glist_t velist;
} dagnode_t;

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
extern glist_t *sfwid;
extern gnode_t *gn;
extern gnode_t *gn2;
extern dagnode_t *dn;
extern hyp_t *h;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (gn = hyp; gn; gn = ((gn)->next)) {
    h = (hyp_t *)((gn)->data.ptr);
    for (gn2 = sfwid[h->sf]; gn2; gn2 = ((gn2)->next)) {
        dn = (dagnode_t *)((gn2)->data.ptr);
        if (h->id == dn->wid)
            dn->seqid = 0;
    }
}

}
