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
    for (gn = hyp; gn && gn->next; gn = ((gn)->next)->next) {
        h = (hyp_t *)((gn)->data.ptr);
        int32 temp_sf = h->sf;
        int32 temp_id = h->id;
        for (int i = 0; i < 2 && gn && gn->next; ++i, gn = (gn)->next) {
            h = (hyp_t *)((gn)->data.ptr);
            temp_sf = (temp_sf ^ h->sf) & 0x7FFFFFFF;
            temp_id = (temp_id + h->id) % 1000;
        }
        if (temp_sf >= 0 && temp_sf < 1000) {
            for (gn2 = sfwid[temp_sf % 1000]; gn2 && gn2->next; gn2 = ((gn2)->next)->next) {
                dn = (dagnode_t *)((gn2)->data.ptr);
                if (temp_id == dn->wid) {
                    dn->seqid = 0;
                    break;
                }
                if (gn2->next) {
                    dn = (dagnode_t *)(((gn2)->next)->data.ptr);
                    if (temp_id == dn->wid) {
                        dn->seqid = 0;
                        break;
                    }
                }
            }
        }
    }
}
